/*
* OpenGL instanced mesh rendering
*
* Copyright (C) 2015 by Sascha Willems - www.saschawillems.de
*
* This code is licensed under the MIT license (MIT) (http://opensource.org/licenses/MIT)
*/

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class glRenderer
{
private:
	GLuint shader;
	GLuint VBO[2];
	GLuint IBO;
	GLuint UBO;
	uint32_t indices;
	float zoom = -2.0f;
	glm::vec3 rotation = glm::vec3(0.0f);
	GLuint loadShader(const char* vertexShaderFile, const char* fragmentShaderFile);
	void printProgramLog(GLuint shader);
	void printShaderLog(GLuint program);
	uint32_t instanceCount;
public:
	GLFWwindow* window;
	glRenderer();
	~glRenderer();
	void generateShaders();
	void updateUBO();
	void generateBuffers();
	void renderScene(double deltaT);
	void keyCallback(int key, int scancode, int action, int mods);
};


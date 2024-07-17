#include <GLFW/glfw3.h>
#include <leif/leif.h>

static int WINDOW_HEIGHT = 720;
static int WINDOW_WIDTH = 1280;
static float WINDOW_MARGIN = 20.0f;
static LfFont TITLE_FONT;
int main(void) {

    glfwInit();


    GLFWwindow *window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Sigma TO DO", NULL, NULL);
    glfwMakeContextCurrent(window);
    lf_init_glfw(WINDOW_WIDTH, WINDOW_HEIGHT, window);

    LfTheme theme = lf_get_theme();
    theme.div_props.color = LF_NO_COLOR;
    lf_set_theme(theme);

    TITLE_FONT = lf_load_font("./fonts/inter-bold.ttf", 40);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0, 0, 0, 1.0f);

        lf_begin();

        lf_div_begin(((vec2s){WINDOW_MARGIN, WINDOW_MARGIN}),
                     ((vec2s){WINDOW_WIDTH - WINDOW_MARGIN * 2.0f,
                         WINDOW_HEIGHT - WINDOW_MARGIN * 2.0f}), true);


        lf_text("Sigma");
        lf_div_end();
        lf_end();

        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

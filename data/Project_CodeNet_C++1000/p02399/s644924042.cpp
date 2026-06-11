#include <cstdio>
#define loop_input(fmt,...) while(~scanf(fmt,__VA_ARGS__))

int main() {
    int a, b;
    loop_input("%d%d", &a, &b) {
        printf("%d %d %lf", a/b, a%b, (double)a/b);
    }
    return 0;
}

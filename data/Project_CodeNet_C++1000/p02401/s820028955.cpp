#include <cstdio>
#define loop_input(fmt,...) while(~scanf(fmt,__VA_ARGS__))

int main() {
    int a, op ,b;
    loop_input("%d %c %d", &a, &op, &b) {
        if (a == 0 && b == 0 && op == '?')  break;
        switch(op) {
            case '+':
                printf("%d\n", a+b);
                break;
            case '-':
                printf("%d\n", a-b);
                break;
            case '*':
                printf("%d\n", a*b);
                break;
            case '/':
                printf("%d\n", a/b);
                break;
        }
    }
    return 0;
}

#include <cstdio>
int main() {
    int a, b;
    scanf ("%d %d", &a, &b);
    printf("%d %d %lf",a / b,a % b,double(a) / double(b));
    return 0;
}
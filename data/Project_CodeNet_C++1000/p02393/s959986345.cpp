#include <stdio.h>

int main(void)
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int small, midium, large;
    if ((a >= b) && (b >= c)) {
        small = c;
        midium = b;
        large = a;
    } else if ((a >= c) && (c >= b)) {
        small = b;
        midium = c;
        large = a;
    } else if ((b >= a) && (a >= c)) {
        small = c;
        midium = a;
        large = b;
    } else if ((b >= c) && (c >= a)) {
        small = a;
        midium = c;
        large = b;
    } else if ((c >= a) && (a >= b)) {
        small = b;
        midium = a;
        large = c;
    } else if ((c >= b) && (b >= a)) {
        small = a;
        midium = b;
        large = c;
    }
    printf("%d %d %d\n", small, midium, large);
    return 0;
}
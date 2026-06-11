#include <stdio.h>

int main() {
    char c;
    scanf("%c", &c);
    if (c == 'z') {
        return 1;
    };
    printf("%c", c + 1);
    return 0;
};
#include <iostream>
#include <stdio.h>

int main() {
    int height, width;

    scanf("%d %d", &height, &width);
    printf("%d %d\n", height * width, (height + width) * 2);

    return 0;
}
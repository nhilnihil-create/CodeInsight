#include <stdio.h>
#include <string.h>

int main() {

    int x;
    char y[105];

    scanf("%d %s", &x, y);

    if(x % 2 == 0 && memcmp(y, y + x / 2, x / 2) == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
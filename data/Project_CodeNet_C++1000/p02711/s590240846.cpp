#include <stdio.h>

int main() {
    char str[4];
    scanf("%s", str);
    if (str[0] == '7' || str[1] == '7' || str[2] == '7') {
        printf("Yes\n");
    }
    else {
        printf("No\n");
    }
    return 0;
}

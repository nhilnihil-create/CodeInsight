#include <stdio.h>

int main() {
    int n, t = 0;
    scanf("%d", &n);
    if (n % 2 == 1) {
        printf("No\n");
        return 0;
    }

    char s[n];
    scanf("%s", s);
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == s[(n / 2) + i]) {
            t++;
        }
    }

    if (t == n / 2) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
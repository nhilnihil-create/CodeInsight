#include <stdio.h>

int main() {
    int n, ct = 0;
    char s[105];
    scanf("%d", &n);
    scanf("%s", &s);
    if (n % 2 != 0) {
        printf("No");
        return 0;
    }
    int half = n / 2;
    for (int i = 0; i < half; i++) {
        if (s[i] == s[i + half]) {
            ct++;
        }
    }
    if (ct == half) {
        printf("Yes");
    } else {
        printf("No");
    }
}
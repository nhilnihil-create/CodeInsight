#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    bool t = false;
    while (n) {
        if (n % 10 == 7) t = true;
        n /= 10;
    }
    printf("%s\n", t?"Yes":"No");
    return 0;
}

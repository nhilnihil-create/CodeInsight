#include <stdio.h>
#include <string.h>

int main() {
    long long int Zx, Yz;
    char dalman[104];
    scanf("%lld", &Zx);
    int u = 0;
    while (Zx > 0) {
        Yz = (Zx - 1) % 26;
        dalman[u++] = 'a' + Yz;
        Zx = (Zx - Yz) / 26;
    }
    int range = strlen(dalman);
    for (range--; range >= 0; range--) {
        printf("%c", dalman[range]);
    }
    return 0;
}

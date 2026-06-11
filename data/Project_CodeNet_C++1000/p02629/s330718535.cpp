#include <stdio.h>
#include <string.h>

int main() {
    long long int tmin, mod;
    char finalname[50];
    scanf("%lld", &tmin);
    int i = 0;
    while (tmin > 0) {
        mod = (tmin - 1) % 26;
        finalname[i++] = 'a' + mod;
        tmin = (tmin - mod) / 26;
    }
    finalname[i] = '\0';
    int len = strlen(finalname);
    for (len--; len >= 0; len--) {
        printf("%c", finalname[len]);
    }
}
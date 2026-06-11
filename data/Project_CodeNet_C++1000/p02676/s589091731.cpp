#include <stdio.h>
#include <string.h>

int main() {
    int k; char str[100];
    scanf("%d", &k);
    scanf("%s", str);

    int sLen = strlen(str);
    if(sLen > k) {
        for(int i = 0; i < k; i++) {
            printf("%c", str[i]);
        }
        printf("...\n");
    } else {
        printf("%s", str);
    }

    return 0;
}
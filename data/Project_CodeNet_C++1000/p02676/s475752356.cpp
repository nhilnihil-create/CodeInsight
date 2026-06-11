#include <stdio.h>
#include <string.h>
int main() {
    int kata; 
	char huruf[100];
    scanf("%d", &kata);
    scanf("%s", huruf);
    int sLen = strlen(huruf);
    if(sLen > kata) {
        for(int i = 0; i < kata; i++) {
            printf("%c", huruf[i]);
        }
        printf("...\n");
    } else {
        printf("%s", huruf);
    }
    return 0;
}
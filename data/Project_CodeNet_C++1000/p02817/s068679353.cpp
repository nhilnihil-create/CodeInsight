#include <stdio.h>


int main() {
    char str1[102]="run";
    char str2[102]="fast";
    scanf("%s %s", &str1, &str2);
    printf("%s%s\n", str2, str1);
    return 0;
    
}
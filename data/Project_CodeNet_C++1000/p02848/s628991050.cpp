#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[10000];
    scanf("%s", str);

    for (int i=0; str[i]!='\0'; i++){
        int temp = str[i] + n;
        if (temp > 90){
            printf("%c", temp-26);
        }
        else{
            printf("%c", temp);
        }
    }
    printf("\n");
    return 0;
}
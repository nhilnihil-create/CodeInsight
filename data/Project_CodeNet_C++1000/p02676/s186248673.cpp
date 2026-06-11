#include<stdio.h>
#include<string.h>
int main(){
    int x;
    char str[101];
    scanf("%d", &x);
    scanf("%s", &str);
    int len = strlen(str);

    if(x < len){
        for(int i = 0; i < x; i++){
            printf("%c", str[i]);
        }
        printf("...");
    }else{
        printf("%s", str);
    }


}
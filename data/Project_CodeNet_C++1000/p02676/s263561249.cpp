#include<stdio.h>
#include<string.h>

int main(){
    int k, l;
    char str[105];
    scanf("%d%s", &k, str);
    l = strlen(str);
    for (int i=0 ; i<k ; i++){
        if (str[i]=='\0'){
            break;
        }
        printf("%c", str[i]);
    }
    if (l>k){
        printf("...");
    }
    puts("");
    return 0;
}
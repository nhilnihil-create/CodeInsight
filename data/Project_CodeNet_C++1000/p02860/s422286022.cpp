#include <stdio.h>
 
int main(){
    int a;
    scanf("%d", &a);
    char str[a];
    scanf("%s", str);
    int flag = 1;
    if(a%2 != 0){
        flag = 0;
    }
    else{
        for(int i = 0, j=a/2;  i<a/2; i++, j++){
            if(str[i] != str[j]){
                flag = 0;
                break;
            }
        }
    }
    
    flag ? printf("Yes\n") : printf("No\n");
    
    return 0;
}
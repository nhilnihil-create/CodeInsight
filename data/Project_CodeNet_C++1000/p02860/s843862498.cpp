#include <stdio.h>

bool x(int n, char str[]){
    for(int i=0;i<n/2;i++){
        if(str[i] != str[i+n/2]){
            return false;
        }
    }
    return true;
}


int main(){
    int n;
    char str[102];
    scanf("%d %s", &n,str);
    (n % 2 == 0 && x(n,str)) ? puts("Yes") : puts ("No");
    
    
    
    
    return 0;
}
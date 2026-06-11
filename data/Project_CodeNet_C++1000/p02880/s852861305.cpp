#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    
    for(int i=1;i <10 ;i++){
        if(n % i == 0 &&n/i <10){
            puts("Yes\n");
            break;
            
        }
        else if(i==9){
            puts("No\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

int main(void){
    int N,X,T,amari,ans;

    scanf("%d %d %d",&N ,&X, &T);

    amari = N % X;
    if(amari != 0)
    {
        ans = (N / X + 1) * T; 
    }
    else
    {
        ans = (N / X) * T; 
    }
    

    
    printf("%d\n",ans);

    return 0;
    
}



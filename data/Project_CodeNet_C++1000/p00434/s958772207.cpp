#include <stdio.h>
#define N 30

int main(void){
    int flg[N+1];
    int id;
    
    for (int i=1; i<=N; i++) flg[i]=0;
    while (scanf("%d", &id)!=EOF){
        flg[id]=1;
    }
    
    for (int i=1; i<=N; i++){
        if (flg[i]==0) printf("%d\n",i);
    }
    
    return 0;
}
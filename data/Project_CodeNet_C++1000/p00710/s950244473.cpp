#include<stdio.h>
int w[60], R, n, p, c, tw[60];
int main(){
    int i;
    while(1){
        scanf("%d%d",&n,&R);
        if(!n)break;
        for(i=1;i<=n;i++)w[i]=n-i+1;
        while(R--){
            scanf("%d%d",&p,&c);
            for(i=1;i<=n;i++)tw[i] = w[i];
            for(i=1;i<=c;i++)w[i]=tw[i+c];
            for(i=1;i<=c;i++)w[i]=tw[i+p-1];
            for(i=c+1;i<p+c;i++)w[i]=tw[i-c];
            for(i=p+c;i<=n;i++)w[i]=tw[i];
        }
        printf("%d\n",w[1]);
    }
}
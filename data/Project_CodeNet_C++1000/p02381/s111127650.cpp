#include <stdio.h>
#include <math.h>
int main(){
    int n,temp;
    double tot,t;
    while(1){
        scanf("%d",&n);
        if(n==0)return 0;
        tot=t=0;
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            tot+=temp*temp;
            t+=temp;
        }
        printf("%lf\n",sqrt((tot-t*t/n)/n));
    }
}
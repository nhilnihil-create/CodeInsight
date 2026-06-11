#include <stdio.h>
#include <math.h>


int main(){
    int n,s,i;
    double sq,su;
    scanf("%d",&n);
    while(n){
        sq = su = 0;
        for(i=0;i<n;i++){
            scanf("%d",&s);
            sq += s*s;
            su += s;
        }
        sq /= n;
        su /= n;
        printf("%f\n",sqrt(sq-su*su));
        scanf("%d",&n);
    }
}
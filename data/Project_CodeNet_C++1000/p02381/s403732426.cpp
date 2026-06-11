#include<stdio.h>
#include<math.h>
int main(){
    int i,j;
    int l=0;
    double r[1000];
    for( ; ; ){
        int n;
        double s;
        double m=0;
        double t=0;
        scanf("%d", &n);
        if(n==0) break;
        for(i=0; i<n; i++){
            scanf("%lf ",&s);
            m+=s;
            t+=s*s;
        }
        m=m/(double)n;
        m=m*m;
        t=t/(double)n;
        r[l]=t-m;
        l++;
        printf("%f\n", sqrt(r[l-1]));
    }
    return 0;
}
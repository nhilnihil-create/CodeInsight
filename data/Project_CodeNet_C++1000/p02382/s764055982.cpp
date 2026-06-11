#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a, b) (a)>(b)?(a):(b)
int main(){
    int i, j;
    int n;
    double a[2][100];
    double reg[4]={0};
    scanf("%d", &n);
    for(i=0; i<2; i++)for(j=0; j<n; j++)scanf("%lf", &a[i][j]);
    for(i=0; i<n; i++){
        a[0][i]=abs(a[0][i]-a[1][i]);
        reg[0]+=a[0][i];//
        reg[1]+=a[0][i]*a[0][i];
        reg[2]+=a[0][i]*a[0][i]*a[0][i];
        reg[3]=max(reg[3], a[0][i]);//
    }
    reg[1]=sqrt(reg[1]);
    reg[2]=pow(reg[2], 1.0/3.0);
    for(i=0; i<4; i++)printf("%f\n",reg[i]);
    return 0;
}
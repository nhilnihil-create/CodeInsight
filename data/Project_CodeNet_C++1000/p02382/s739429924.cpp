#include <stdio.h>
#include <math.h>

int main(){
    int n,x[100],y[100];
    int i;
    double ma=0,eu=0,m3=0,ch=0,di;
    scanf("%d",&n);
    for(i=0;i<n;i++)scanf("%d",&x[i]);
    for(i=0;i<n;i++)scanf("%d",&y[i]);
    for(i=0;i<n;i++){
        di = fabs(x[i]-y[i]);
        ma += di;
        eu += di*di;
        m3 += di*di*di;
        if(ch<di)ch = di;
    }
    printf("%f %f %f %f\n",ma,sqrt(eu),pow(m3,1./3),ch);
}
#include <cstdio>
#include <cmath>
#include <algorithm>
#define REP(val,times) for(int val = 0;val < times;val++)
int x[1001],y[1001];

int main(){
    int n;
    double p1 = 0.0,p2 = 0.0,p3 = 0.0,pinf = 0.0;
    scanf("%d",&n);
    REP(i,n)
        scanf("%d",&x[i]);
    REP(i,n)
        scanf("%d",&y[i]);
    REP(i,n){
        p1 += fabs(x[i] - y[i]);
        p2 += (x[i] - y[i]) * (x[i] - y[i]);
        p3 += fabs((x[i] - y[i]) * (x[i] - y[i]) * (x[i] - y[i]));
        pinf = fmax(pinf,fabs(x[i] - y[i]));
    }
    printf("%.6lf\n",p1);
    printf("%.6lf\n",sqrt(p2));
    printf("%.6lf\n",pow(p3,1.0 / 3.0));
    printf("%.6lf\n",pinf);

    return 0;
}

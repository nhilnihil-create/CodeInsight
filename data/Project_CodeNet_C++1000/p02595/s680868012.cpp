#include<stdio.h>
#include<math.h>
int main(){
    int n, d;
    double x[1000000],y[1000000];
    double z;
    int ans=0;
    scanf("%d %d", &n, &d);
    for(int i=0;i<n;i++) scanf("%lf %lf",&x[i], &y[i]);
    for(int i=0; i<n ;i++){
        z=sqrt(x[i]*x[i]+y[i]*y[i]);
        if(z<=d) ans++;
    }
    printf("%d", ans);
    return 0;
}
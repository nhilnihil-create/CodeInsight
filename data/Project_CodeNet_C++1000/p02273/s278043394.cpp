#include<stdio.h>
#include<math.h>

void Koch(int n,double p1x,double p1y,double p2x,double p2y){
    if(n <= 0)
        return ;

    double sx = (p1x * 2.0 + p2x) / 3.0,sy = (p1y * 2.0 + p2y) / 3.0;
    Koch(n - 1,p1x,p1y,sx,sy);
    printf("%lf %lf\n",sx,sy);
    double tx = (p1x + p2x * 2.0) / 3.0,ty = (p1y + p2y * 2.0) / 3.0;
    double ux = 0.5 * (tx + sx) - sqrt(3) * 0.5 * (ty - sy),uy = sqrt(3) * 0.5 * (tx - sx) + 0.5 * (ty + sy);
    Koch(n - 1,sx,sy,ux,uy);
    printf("%lf %lf\n",ux,uy);
    Koch(n - 1,ux,uy,tx,ty);
    printf("%lf %lf\n",tx,ty);
    Koch(n - 1,tx,ty,p2x,p2y);

}

int main(void){
    int n;
    scanf("%d",&n);
    printf("0.00000000 0.00000000\n");
    Koch(n,0.0,0.0,100.0,0.0);
    printf("100.00000000 0.00000000");
    return 0;
}
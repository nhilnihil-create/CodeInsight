#include<cstdio>
double const sqrt3=1.7320508075688772;
void koch(int n,double x1=0,double y1=0,double x2=100,double y2=0){
    if(x1==0&&y1==0&&x2==100&&y2==0)printf("%.8lf %.8lf\n",x1,y1);
    if(n>0){
        double dx=(x2-x1)/3, dy=(y2-y1)/3,
               sx=x1+dx, sy=y1+dy, tx=x2-dx, ty=y2-dy,
               ux=sx+(dx-sqrt3*dy)/2, uy=sy+(sqrt3*dx+dy)/2;
        koch(n-1,x1,y1,sx,sy);
        koch(n-1,sx,sy,ux,uy);
        koch(n-1,ux,uy,tx,ty);
        koch(n-1,tx,ty,x2,y2);
    }else printf("%.8lf %.8lf\n",x2,y2);
}
int main(){
    int n;
    scanf("%d",&n);
    koch(n);
    return 0;
}

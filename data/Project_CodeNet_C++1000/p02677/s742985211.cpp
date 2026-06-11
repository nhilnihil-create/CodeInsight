#include <stdio.h>
#include <math.h>
int main(){
	int a,b,h,m,c,d,t;
	double e,ans;
	scanf("%d%d%d%d",&a,&b,&h,&m);//按顺时针方向，分针与12点的夹角是(m/60)*2*PI
	c=60*h+m,d=12*m;//按顺时针方向，时针与12点的夹角是(h+m/60)/12*2*PI
	//(h+m/60)/12*2*PI-(m/60)*2*PI=((60*h+m)-12*m)/720*2*PI
	if(c<d)t=c,c=d,d=t;//找出时针，分针，走过大的角度
	e=(c-d)*2*M_PI/720;//c-d，让大角减小角
	ans=sqrt(a*a+b*b-2*a*b*cos(e));//余弦定理
	printf("%.12lf\n",ans);
	return 0;
}
 
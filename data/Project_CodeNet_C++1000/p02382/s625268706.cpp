#include <stdio.h>
#include <math.h>
#include <string.h>
#define rep(i,a,n) for(int i=a;i<n;i++)

int main(){
	int n;
	double x[101]={0},y[101]={0},p[10]={0};
	scanf("%d",&n);
	rep(i,0,n) scanf("%lf",&x[i]);
	rep(i,0,n) scanf("%lf",&y[i]);
	rep(i,0,n){
		p[1]+=fabs(x[i]-y[i]);
		p[2]+=pow(fabs(x[i]-y[i]),2.0);
		p[3]+=pow(fabs(x[i]-y[i]),3.0);
		if(p[4]<fabs(x[i]-y[i])) p[4]=fabs(x[i]-y[i]);
	}
	p[2]=pow(p[2],0.5);
	p[3]=pow(p[3],1.0/3.0);
	rep(i,1,5) printf("%.10lf\n",p[i]);
	return 0;
}
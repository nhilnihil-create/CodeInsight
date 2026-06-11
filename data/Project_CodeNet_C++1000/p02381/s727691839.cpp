#include <stdio.h>
#include <math.h>
#include <string.h>
#define rep(i,a,n) for(int i=a;i<n;i++)

int main(){
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		double s[1001]={0},ave=0,a=0;
		rep(i,0,n){
			scanf("%lf",&s[i]);
			ave+=s[i];
		}
		ave/=(double)n;
		rep(i,0,n){
			a+=pow(s[i]-ave,2);
		}
		a/=(double)n;
		a=sqrt(a);
		printf("%.10lf\n",a);
	}
	return 0;
}
#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
int main(){
	double x1,y1,x2,y2,a,b,c,ans;
	cin>>x1>>y1>>x2>>y2;
	a=x1-x2;
	b=y1-y2;
	ans=sqrt(a*a+b*b);
	printf("%.8f",ans);
	
}
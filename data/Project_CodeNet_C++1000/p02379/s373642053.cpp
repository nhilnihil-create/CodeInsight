#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<math.h>
using namespace std;


long double a(long double x){
	if(x<0)return -x;
	
	return x;
}

int main(){
 double x1,y1,x2,y2;
scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
long double x,y;

/*if(x1<0&&x2>=0){
	x=a(x1)+x2;
}
else if(x2<0&&x1>=0){
	x=x1+a(x2);
}
else x=max(a(x1),a(x2))-min(a(x1),a(x2));

if(y1<0&&y2>=0){
	y=a(y1)+y2;
}
else if(y2<0&&y1>=0){
	y=y1+a(y2);
}
else y=max(a(y1),a(y2))-min(a(y1),a(y2));*/
	//printf("%f : %f",x,y);
		double ans=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		printf("%f\n",ans);
return 0;
}
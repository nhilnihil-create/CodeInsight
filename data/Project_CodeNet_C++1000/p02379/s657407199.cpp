#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
int main(){
	double x1,x2,y1,y2,ans1;
	cin>>x1>>y1>>x2>>y2;
		ans1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		printf("%.9f\n",ans1);
	return 0;
}
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main(void){
	double a,b,c,d,x,y;
	cin>>a>>b>>c>>d;
	x = c-a;
	y = b-d;
	if(x<0)x =x*-1;
	if(y<0)y =y*-1;
	printf("%lf\n",sqrt(x*x+y*y));
	return 0;
}

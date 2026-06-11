#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(){
	double a,b,c,d;
	cin>>a>>b>>c>>d;

	double ans=sqrt(abs(c-a)*abs(c-a)+abs(d-b)*abs(d-b));
	printf("%.7f\n",ans);
	return 0;
}
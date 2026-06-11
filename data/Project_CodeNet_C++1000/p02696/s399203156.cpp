#include<bits/stdc++.h>

using namespace std;

int main(){
	double a,b,n;
	scanf("%lf%lf%lf",&a,&b,&n);
	printf("%.0lf\n",floor(a*((n<b?n:b-1)/b-floor((n<b?n:b-1)/b))));
}
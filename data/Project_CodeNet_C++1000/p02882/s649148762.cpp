#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define LL long long


int main(){
	// sengen
	double a,b,x;
	// nyuryoku
	cin >> a >> b >> x;
	// keisan
	if(x <= a*a*b/2){
		double kodo = atan(2*x/a/b/b);
		kodo = kodo*180/M_PI;
		printf("%.8lf\n",90-kodo);
	}else{
		double kodo = atan(a*a*a/2/(a*a*b - x));
		kodo = kodo*180/M_PI;
		printf("%.8lf\n",90-kodo);
	}
	// syutsuryoku
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INFL 0x6fffffffffffffffLL

int main() {
	ll		a,b,d,w,h,i,j,k,l,m,n,z;
	double	ans = 0;
	cin >> a >> b >> h >> m;
	
	double x = m*6;
	double y = h*30+(double)m/2;
	
	double rad = abs(x-y);
	if (rad>180.0) rad = 360.0 - rad;
	
	//cout << cos(0) << endl;
	//cout << cos(180.0/180.0*M_PI) << endl;

	ans = sqrt( a*a + b*b - 2*a*b*cos(rad/180.0*M_PI) );
	printf("%.10f\n",ans);
	return 0;
}

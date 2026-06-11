#include <bits/stdc++.h>
using namespace std;

int main() {
	double a, b, h, m;
	cin >> a >> b >> h >> m;
	
	double ad = (h*60.0+m)/720.0;
	double bd = m/60.0;
	double diff = min(abs(bd-ad),1.0-abs(bd-ad));

	double ansans = a*a + b*b - 2.0*a*b*cos(diff*2.0*M_PI);
	double ans = sqrt(ansans);

	printf("%.12lf",ans);
}

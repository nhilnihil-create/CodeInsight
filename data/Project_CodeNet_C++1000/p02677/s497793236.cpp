#include<iostream>
#include<math.h>
#include <iomanip>


using namespace std;
const double PI = acos(-1.0);
int main(){
	double a,b,h,m;
	cin >> a >> b >> h >> m;
	long double mdu = (long double)m/60.0;
	long double hdu = ((long double)h + (long double)m/60.0)/12.0;
	long double difdu = hdu - mdu;
	long double ans = sqrt((long double)a*a + (long double)b*b - (long double)2* a * b * cos(difdu * 2*PI));
	cout << setprecision(20) << ans;
	return 0; 
}
#include<iostream>
#include<math.h>
#include <iomanip>


const double PI = acos(-1.0);
using namespace std;
int main(){
	double a,b,h,m;
	cin >> a >> b >> h >> m;
	double mdu = m*6;
	long double hdu = (long double)30*h + (long double)0.5 * m;
	long double difdu = hdu - (long double)mdu;
	long double ans = sqrt((long double)a*a + (long double)b*b - 2* a * b * cos(difdu * PI / 180.0 ));
	cout << setprecision(20) << ans;
	return 0; 
}
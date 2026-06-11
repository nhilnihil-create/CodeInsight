#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(){
	long double a,b,h,m;
	cin >> a >> b >> h >> m;
	
	long double hang = h*30 + (m/60)*30;
	long double mang = m*6;
	long double ang = abs(mang - hang);
	long double pi = 3.14159265358979323846;
	long double cosang = cos(ang * pi/180);
	long double res = sqrt(a*a + b*b - 2*a*b*cosang);
	
	cout << fixed << showpoint;
	cout << setprecision(20);
	cout << res << endl;
	
	return 0;
	
	
} 
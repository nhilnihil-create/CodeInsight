#include <bits/stdc++.h>
const double pi = 3.141592653589793238463;
using namespace std;
int main(){
	int a, b, h, m;
	cin >> a >> b >> h >> m;
	double time = h + (double)m/60;
	double angle1_hr = (pi/6)*time;
	double angle1_min = 2*pi*time;
	double angle2_hr = 2*pi - (ceil(time/12)*2*pi - angle1_hr);
	double angle2_min = 2*pi - (ceil(time)*2*pi - angle1_min);
	double angle = abs(angle2_hr - angle2_min);
	if(angle > 2*pi){
		angle = 2*pi - angle;
	}
	double ans = sqrt(pow(a, 2)+pow(b, 2)-2*a*b*cos(angle));
	cout.precision(20);
	cout << fixed << ans;
}

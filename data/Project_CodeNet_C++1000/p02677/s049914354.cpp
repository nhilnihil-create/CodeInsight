#include <bits/stdc++.h>
#include <math.h>
using namespace std;
double pi = 3.1415926535;

void solve(){
	long double a , b, h, m;
	cin >> a >> b >> h >> m;
	long double hour_angle = 0.5 * (h * 60 + m);
	long double minute_angle = 6.0 * m;
	long double angle = abs(hour_angle - minute_angle);
	//angle = min(360 - angle, angle);
	//angle = 0.0174533 * angle;
	long double ans = (a * a) + (b * b)- ((2 * a * b ) * cos(angle * pi/ 180));
	ans = sqrt(ans);
	printf("%0.10Lf\n", ans);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}

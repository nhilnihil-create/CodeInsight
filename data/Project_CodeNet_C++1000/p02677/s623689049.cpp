#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
#define PI 3.14159265358979323846264338327950

int main() {
	ll a, b, h, m;
	long double minute, hour, rad, ans=0;

	cin >> a >> b >> h >> m;

	minute = (long double)m/60.0;
	hour = (long double)m /720.0 + (long double)h /12.0;
	rad = 2 * PI*(minute-hour);
	ans = sqrt(a*a + b*b - 2*a*b*cos(rad));
  
	printf("%20.20Lf\n", ans);

	return 0;
}
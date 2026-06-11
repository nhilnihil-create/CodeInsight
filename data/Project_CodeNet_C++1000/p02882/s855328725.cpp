#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
const int inf = 1e+9;


int main() {
	double a, b, x;
	cin >> a >> b >> x;
	double water = x / a;
	//cout << "water:" << water << endl;

	double mid_angle = atan2(b , a);

	double ok = 0;
	double ng = M_PI / 2.0;

	while(fabs(ok - ng) > 0.000000000001) {
		double mid = (ok + ng) / 2;
		double cur;
		//cout << "mid:" << mid << " mid_angle:" << mid_angle << endl;
		if (mid < mid_angle) {
			cur = a * b - a *  a * tan(mid) / 2.0;
			//cout << "mid_angle < mid" << endl;
		} else {
			cur = b * b * tan(M_PI / 2.0 - mid) / 2.0;
			//cout << "mid_angle >= mid" << endl;

		}
		//cout << "ok:" << ok << " ng:" << ng << " cur:";
		//cout << cur << endl;
		if (cur >= water) {
			ok = mid;
		} else { 
			ng = mid;
		}
	}

	cout << fixed << setprecision(10) << ok  * 180.0 / M_PI << endl;
	return 0;
}

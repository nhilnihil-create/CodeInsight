#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
int main() {
	ll w, h, x, y;
	cin >> w >> h >> x >> y;
	double ans = (double)w * h * 0.5;
	printf("%.12f ", ans);
	if (w == x * 2 && h == y * 2) {
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
const double PI = acos(-1);
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	double a, b, x; cin >> a >> b >> x;
	double angle;
	if (2 * x > a * a * b) {
		angle = atan(2 * (a*a*b - x) / (a*a*a)) * (180/PI);
	} else {
		angle = (PI/2 - atan(2*x / (b*b*a))) * (180/PI);
	}
	cout << setprecision(10) << angle << endl;
	return 0;
}
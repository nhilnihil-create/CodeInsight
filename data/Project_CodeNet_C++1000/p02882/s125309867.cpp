#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iomanip>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i, j, n) for(int i = (j); i < (n); ++i)
#define rrep(i, j, n) for(int i = (n) - 1; (j) <= i; --i)
constexpr ll MOD = 1000000007;
constexpr ll INF = 1LL << 60;

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	double a, b, x;
	cin >> a >> b >> x;

	x /= a;

	cout << fixed << setprecision(10);
	if (x < a * b / 2.0) {
		double y = 2.0 * x / b;
		cout << atan2(b, y) * 180 / 3.14159265358979; 
	}
	else {
		double y = (2.0 * a * b - 2.0 * x) / a;
		cout << atan2(y, a) * 180.0 / 3.14159265358979;
	}
	return 0;

}

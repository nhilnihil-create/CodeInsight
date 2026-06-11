#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int main() {
	double a, b, x;
	cin >> a >> b >> x;

	x /= a;
	cout << fixed << setprecision(10);
	if (x > a * b / 2) cout << atan2((a * b - x) * 2, a * a) * 180 / PI << endl;
	else cout << atan2(b * b, x * 2) * 180 / PI << endl;
}
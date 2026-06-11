#include <bits/stdc++.h>
#define PI 3.14159265359
#define NIL (-1)
#define LL long long
using namespace std;
const int64_t MOD = 1e9 + 7;
const int INF = INT_MAX;

int64_t GCD(int64_t a, int64_t b) {
	if (!b) return a;
	else return GCD(b, a % b);
}

int64_t LCM(int64_t a, int64_t b) {
	int64_t gcd = GCD(a, b);
	int64_t n, m;
	n = a / gcd;
	m = b / gcd;
	return gcd * n * m;
}

int main() {
	int64_t A, B, C, D;
	cin >> A >> B >> C >> D;

	vector<int64_t> a(3), b(3);
	int64_t g = LCM(C, D);
	a[0] = B / C;	a[1] = B / D;	a[2] = B / g;
	b[0] = (A-1) / C;	b[1] = (A - 1) / D;	b[2] = (A - 1) / g;

	int64_t ret = B - A + 1;
	int64_t n = (a[0] - b[0]) + (a[1] - b[1]) - (a[2] - b[2]);
	ret -= n;

	cout << ret << endl;
}
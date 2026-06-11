#include <bits/stdc++.h>
using namespace std;

const long double PI = 3.1415926535887;

long double R(int a) {
	return (long double)a * a;
}

long double D(pair<int, int> a) {
	return sqrt(R(a.first) + R(a.second));
}

long double K(int a, int b) {
	if(a == 0 && b == 0) return 0.00;
	long double x = a;
	x /= D({a, b});
	x = acos(x);
	x *= 180.00 / PI;
	if(b >= 0) return x;
	return 360.00 - x;
}

long double K(pair<int, int> a) {
	return K(a.first, a.second);
}

pair<int, int> J(pair<int, int> a, pair<int, int> b) {
	a.first += b.first;
	a.second += b.second;
	return a;
}

pair<int, int> S(pair<int, int> a, pair<int, int> b) {
	a.first -= b.first;
	a.second -= b.second;
	return a;
}

pair<int, int> M(pair<int, int> a, pair<int, int> b) {
	if(D(a) > D(b)) return a;
	return b;
}

const int N = 102;
int n;
pair<int, int> r[N], fp;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> r[i].first >> r[i].second;
	}
	sort(r + 1, r + n + 1, [](pair<int, int> a, pair<int, int> b) { return K(a) < K(b); } );
	for(int i = 1; i <= n; ++i) {
		r[i] = J(r[i - 1], r[i]);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(i <= j) {
				fp = M(fp, S(r[j], r[i - 1]));
			} else {
				fp = M(fp, J(S(r[n], r[i - 1]), r[j]));
			}
		}
	}
	cout << setprecision(20) << D(fp) << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

long long mod(long long a, long long m) {
	a %= m;
	return a >= 0 ? a : a+m;
}

struct P
{
	using T = long long;
	T x, y;
	P(T x=0, T y=0) : x(x), y(y) {}

	friend ostream &operator<<(ostream &os, const P &a) {
		return os << '(' << a.x << ',' << a.y << ')';
	}

	int quadrant() const {
		if (x > 0 && y >= 0) return 0;
		else if (x <= 0 && y > 0) return 1;
		else if (x < 0 && y <= 0) return 2;
		else if (x >= 0 && y < 0) return 3;
		else return 4;
	}
};

long long cross_product(const P &a, const P &b) {
	return (long long)a.x * b.y - (long long)a.y * b.x;
}

bool comp_argument_sort(const P &a, const P &b) {
	int a_quad = a.quadrant(), b_quad = b.quadrant();
	if (a_quad != b_quad) return a_quad < b_quad;
	else return cross_product(a, b) > 0;
}

int main() {
	int n;
	cin >> n;
	vector<P> v;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) continue;
		v.emplace_back(x, y);
	}
	if (v.size() == 0) {
		cout << 0 << endl;
		return 0;
	}
	n = v.size();
	sort(v.begin(), v.end(), comp_argument_sort);
	long long ans2 = 0;
	for (int i = 0; i < n; i++) {
		long long X = 0, Y = 0;
		for (int j = 0; j < n; j++) {
			int idx = mod(i+j, n);
			X += v[idx].x, Y += v[idx].y;
			long long now = X*X + Y*Y;
			ans2 = max(ans2, now);
		}
	}
	double ans = sqrt(ans2);
	cout << fixed << setprecision(20) << ans << endl;
	return 0;
}
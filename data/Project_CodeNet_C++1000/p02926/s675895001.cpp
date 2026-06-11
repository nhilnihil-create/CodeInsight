#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)


struct Problem {

	struct Point {
		LL x, y;
		bool operator<(const Point &r) const {
			if (x * r.x > 0) return y * r.x < r.y * x;
			if (x * r.x < 0) return x > 0;
			if (r.x != 0) return !(r < *this);
			if (x == 0) return y < r.y;
			if (r.y > 0) return x > 0;
			return false;
		}
	};

	void Solve() {
		UL N; cin >> N;
		Point P[100];
		rep(i, N) cin >> P[i].x >> P[i].y;
		sort(P, P + N);

		LL ans = 0;
		for(UL s = 0; s < N; s++) {
			LL X = 0, Y = 0;
			for (UL t = 0; t < N; t++) {
            	UL tt = (s + t) % N;
				X -= P[tt].x; Y -= P[tt].y;
				ans = max(ans, X * X + Y * Y);
				//cout << X * X + Y * Y << endl;
			}
		}
		//cout << endl;
		cout << sqrt(double(ans)) << endl;
	}

	Problem();
};
int main() {
	unique_ptr<Problem> p(new Problem());
	p->Solve();
	return 0;
}
Problem::Problem() {
	cout << fixed << setprecision(10);
}

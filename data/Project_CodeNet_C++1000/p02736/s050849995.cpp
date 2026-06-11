#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

template<class Ty>
using passive_queue = priority_queue<Ty, vector<Ty>, greater<Ty>>;

struct Problem {

	void Solve() {
		UL N; cin >> N;
		bool x1, x2; x1 = x2 = false;
		bool a1 = false;
		int buf; {char c; cin >> c; buf = c - '0'; }
		int even = 0;
		rep(i, N - 1) {
			char c; cin >> c; c -= '0';
			buf = abs(buf - c);
			if (buf == 1) a1 = true;

			if (i != 0) {
				int t = N - i - 1;
				while ((t & 1) == 0) { even++; t >>= 1; }
				t = i;
				while ((t & 1) == 0) { even--; t >>= 1; }
			}
			if (even == 0) {
				if (buf == 1) x1 = !x1;
				if (buf == 2) x2 = !x2;
			}
			buf = c;
		}
		if (x1) cout << 1 << endl;
		else if (a1) cout << 0 << endl;
		else cout << (x2 ? 2 : 0) << endl;
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

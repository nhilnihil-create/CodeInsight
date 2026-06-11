#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	bool S[200000];

	void Solve() {
		UL N; cin >> N;
		UL A, B, C, D; cin >> A >> B >> C >> D;
		A--; B--; C--; D--;
		rep(i, N) { char c; cin >> c; S[i] = c == '#'; }
		if (D < C) {
			UL ok = false;
			for (UL i = B; i <= D; i++) {
				if (i == N - 1) continue;
				if (!(S[i - 1] || S[i] || S[i + 1])) ok = true;
			}
			if(!ok) { cout << "No" << endl; return; }
		}
		for (UL i = A; i < C; i++) {
			if (S[i] && S[i + 1]) { cout << "No" << endl; return; }
		}
		for (UL i = B; i < D; i++) {
			if (S[i] && S[i + 1]) { cout << "No" << endl; return; }
		}
		cout << "Yes" << endl;
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
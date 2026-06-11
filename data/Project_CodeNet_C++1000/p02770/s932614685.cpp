#include <bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL K, Q; cin >> K >> Q;
		vector<ULL> D(K); rep(i, K) cin >> D[i];
		vector<ULL> MD(K);
		rep(i, Q) {
			ULL N, X, M; cin >> N >> X >> M;
			ULL ans = N - 1;
			UL t = (N - 1) / K + 1;
			ULL S, T; S = T = X;
			rep(i, K) {
				if (i == (N - 1) % K) t--;
				MD[i] = D[i] % M;
				T += MD[i] * t;
				if (MD[i] == 0) ans -= t;
			}
			ans -= ((T / M) - (S / M));
			cout << ans << endl;
		}
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

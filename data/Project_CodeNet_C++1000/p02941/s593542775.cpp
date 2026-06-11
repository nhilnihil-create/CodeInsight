#include<bits/stdc++.h>
#include <array>
using namespace std;
using ULL = unsigned long long;
using UL = unsigned;
using LL = long long;
#define rep(i, n) for(UL i = 0; i < (n); i++)

struct Problem {

	void Solve() {
		UL N; cin >> N;
		vector<UL> A(N), B(N);
		rep(i, N) cin >> A[i];
		rep(i, N) cin >> B[i];
		priority_queue<pair<UL, UL>> Q;
		rep(i, N) {
			if (A[i] > B[i]) { cout << -1 << endl; return; }
			if (A[i] < B[i]) Q.push({ B[i], i });
		}
		ULL ans = 0;
		while (Q.size()) {
			UL i = Q.top().second; Q.pop();
			UL l = (i + N - 1) % N;
			UL r = (i + 1) % N;
			UL d = B[l] + B[r];
			UL t = (B[i] - A[i]) / d;
			ans += t;
			B[i] -= d * t;
			//rep(i, N) cout << B[i] << " "; cout << endl;
			if (A[i] == B[i]) continue;
			if(B[i] > B[l] && B[i] > B[r]) { cout << -1 << endl; return; }
			Q.push({ B[i], i });
		}
		cout << ans << endl;
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

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

		if (N < 3) {
			cout << "No" << endl;
			return;
		}
		if (N == 3) {
			cout << "Yes" << endl;
			cout << "1 2" << endl;
			cout << "2 3" << endl;
			cout << "3 4" << endl;
			cout << "4 5" << endl;
			cout << "5 6" << endl;
			return;
		}

		UL M = 4;
		while (M * 2 <= N) M *= 2;
		if (N == M) { cout << "No" << endl; return; }
		cout << "Yes" << endl;
		vector<UL> V(M - 1); rep(i, M - 1) V[i] = i + 1;
		if (N % 2 == 0) {
			swap(V[1], V[(N ^ M ^ 1) - 1]);
		}
		vector<pair<UL, UL>> W((N - M + 1) / 2);
		rep(i, (N - M + 1) / 2) {
			W[i] = { M + i * 2, M + i * 2 + 1 };
		}

		rep(i, V.size() - 1) cout << V[i] << " " << V[i + 1] << endl;
		cout << V.back() << " " << (V[0] + N) << endl;
		rep(i, V.size() - 1) cout << (V[i] + N) << " " << (V[i + 1] + N) << endl;

		rep(i, W.size()) {
			cout << W[i].second << " " << W[i].first << endl;
			cout << W[i].first << " " << 1 << endl;
			cout << 1 << " " << (W[i].second + N) << endl;
			cout << (W[i].second + N) << " " << (W[i].first + N) << endl;
		}
		if (N % 2 == 0) {
			cout << M << " " << N << endl;
			cout << V[1] << " " << (N + N) << endl;
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

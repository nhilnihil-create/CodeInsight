#include <bits/stdc++.h>

using namespace std;

constexpr int MAXN = 1000000;

char X[MAXN + 2];

int main() {
	int N;
	cin >> N >> X;
	int m = 0;
	for(int i = 0; i < N; i++) {
		X[i] -= '1';
		m |= 1 << X[i];
	}
	m = !(m & 2);
	for(int i = 0; i < N; i++)
		if(X[i] == 2)
			X[i] = m;
	int comb = __builtin_ctz(N - 1);
	bool res = X[0] ^ X[N - 1];
	for(int i = 1; i < N - 1; i++) {
		if(comb == 0) res ^= X[i];
		comb += __builtin_ctz(N - 1 - i);
		comb -= __builtin_ctz(i + 1);
	}
	int ans = res ? (m ? 2 : 1) : 0;
	cout << ans << '\n';
}

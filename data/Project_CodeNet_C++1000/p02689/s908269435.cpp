#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N, M;
	cin >> N >> M;

	vector<ll> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}

	vector<ll> ans(N, 0);
	for (int i = 0; i < M; ++i) {
		int A, B;
		cin >> A >> B;
		A--;
		B--;
		ans[A] = max(ans[A], H[B]);
		ans[B] = max(ans[B], H[A]);
	}

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (ans[i] < H[i]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}


// E - Divisible Substring

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int ctoi(char c) {
	return c - '0';
}

map<int, int> rem_list;

int main() {
	int N, P;
	string S;
	cin >> N >> P >> S;

	ll ans;

	if (P == 2) {
		ans = 0;
		for (int i=0; i<N; i++) {
			if (ctoi(S[i]) % 2 == 0) {
				ans += i+1;
			}
		}

		cout << ans << endl;
		return 0;
	}

	if (P == 5) {
		ans = 0;
		for (int i=0; i<N; i++) {
			if (ctoi(S[i]) % 5 == 0) {
				ans += i+1;
			}
		}

		cout << ans << endl;
		return 0;
	}

	int mod_k = 0; // 部分文字列kのMOD P
	int d = 1;
	for (int i=N-1; i>=0; i--) {
		mod_k = (ctoi(S[i]) * d + mod_k) % P;
		rem_list[mod_k]++;

		d = (d * 10) % P; // 10^i も MOD P にしておく
	}

	ans = rem_list[0]; // 最後の桁まで使う場合

	for (auto itr : rem_list) {
		ll cnt = itr.second;
		ans += cnt * (cnt - 1) / 2;
	}

	cout << ans << endl;

	return 0;
}
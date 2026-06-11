
// A - Connection and Disconnection

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int main() {
	string S;
	cin >> S;

	ll K;
	cin >> K;

	string S3 = S + S + S;
	int k = 0;
	int cnt[3] = {0, 0, 0};
	for (int i=0; i<3; i++) {
		for (int j=0; j<S.size(); j++) {
			if (k == 0) {
				k++;
				continue;
			}

			if (S3[k] == S3[k-1]) {
				cnt[i]++;
				S3[k] = '#';
			}

			k++;
		}
	}

	ll ans;
	if (cnt[1] == cnt[2]) {
		// ABBBパターン
		ans = cnt[0] + cnt[1] * (K-1);
	} else {
		// ABABパターン
		if (K % 2 == 0) {
			ans = (cnt[0] + cnt[1]) * (K / 2);
		} else {
			ans = (cnt[0] + cnt[1]) * (K / 2) + cnt[0];
		}
	}

	cout << ans << endl;

	return 0;
}
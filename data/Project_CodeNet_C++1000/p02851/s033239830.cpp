
// E - Rem of Sum is Num

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

ll A[200000];
ll cumA[200001];
ll M[200001];

int main() {
	ll N, K;
	cin >> N >> K;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	for (int i=1; i<=N; i++) {
		cumA[i] = cumA[i-1] + A[i-1];
		M[i] = (cumA[i] - i) % K;
	}

	ll ans = 0;

	// **** debug : この方法でカウントするとTLE ****
	/*
	for (int i=0; i<N; i++) {
		for (int j=i+1; j<=N; j++) {
			if ((j - i < K) && (M[i] % K == M[j] % K)) {
				ans++;
			}
		}
	}
	*/

	map<ll, ll> M_cnt; // 0 < j - i < K の範囲でのMの度数分布
	// i = 0
	for (int j=1; j<K && j<=N; j++) {
		M_cnt[M[j]]++;
	}

	for (int i=0; i<N; i++) {
		ans += M_cnt[M[i]];

		// 度数分布をスライド
		M_cnt[M[i+1]]--;
		if (i+K <= N) M_cnt[M[i+K]]++;
	}

	cout << ans << endl;

	return 0;
}
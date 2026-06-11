
// E - Max GCD

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[500];
int rem[500];
ll cum_L[500];
ll cum_R[500];

int main() {
	int N, K;
	cin >> N >> K;

	int A_sum = 0;
	for (int i=0; i<N; i++) {
		cin >> A[i];
		A_sum += A[i];
	}

	// Aの和の約数が答えの候補
	set<int> candidates;
	for (int i=1; i*i<=A_sum; i++) {
		if (A_sum % i == 0) {
			candidates.insert(i);
			candidates.insert(A_sum / i);
		}
	}

	// 候補のそれぞれについて、K以下の操作でAの全ての要素を割り切れるようにできるか判定し、
	// 割り切れるようにできたものの最大値が答え
	int ans = 0;
	for (int X : candidates) {
		ll need = INF; // 全ての要素を割り切れるようにするのに必要な回数

		ll rem_sum = 0;
		for (int i=0; i<N; i++) {
			rem[i] = A[i] % X;
			rem_sum += rem[i];
		}

		sort(rem, rem+N);

		// rem[i] までを減らす操作、rem[i+1]以降を増やす操作に割り当てる

		// cum_L[i]: rem[i]までを減らすときの減らす操作の合計
		cum_L[0] = rem[0];
		for (int i=1; i<N; i++) {
			cum_L[i] = cum_L[i-1] + rem[i];
		}

		// cum_R[i]: rem[i]までを減らすときの増やす操作の合計
		cum_R[N-1] = 0;
		for (int i=N-2; i>=0; i--) {
			cum_R[i] = cum_R[i+1] + (X - rem[i+1]);
		}

		for (int i=0; i<N; i++) {
			if (cum_L[i] == cum_R[i]) {
				need = min(need, cum_L[i]);
			}
		}

		if (need <= K) {
			ans = max(ans, X);
		}
	}

	cout << ans << endl;

	return 0;
}
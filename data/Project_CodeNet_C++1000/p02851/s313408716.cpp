#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

// (A_[i] - A_[j]) mod K = i-j
// (A_[i] - i) mod K = (A_[j] - j)mod K  (j < i)

int main() {
	int N, K;
	cin >> N >> K;
	vector<ll> A(N), A_(N + 1), B(N + 1);
	for (int i = 0; i < N; i++) cin >> A[i];
	A_[0] = 0;
	for (int i = 0; i < N; i++) {
		A_[i + 1] = A_[i] + A[i];
	}
	for (int i = 0; i <= N; i++) {
		B[i] = (A_[i] - i)%K;
	}

	ll ans = 0;
	unordered_map<int, int> cnt;
	for (int i = 0; i <= N; i++) {

		ans += cnt[B[i]];
		cnt[B[i]]++;
		if (i >= K-1) {
			cnt[B[i - K+1]]--;
		}
	}
	cout << ans << endl;
}
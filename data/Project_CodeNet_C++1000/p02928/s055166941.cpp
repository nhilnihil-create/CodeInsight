
//

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
const ll MOD = 1e9 + 7;

// Binary Indexed Tree （indexは1始まり）
// T は +-*/ と 0 を持つ
template<class T> class BIT {
private:
	int N; // 要素数
	vector<T> nodes;

public:
	BIT(int N) {
		this->N = N;
		nodes.assign(N+1, 0);
	}

	// index k の値にxを加える
	void add(int k, T x) {
		for (int i=k; i<=N; i += (i & -i)) {
			nodes[i] += x;
		}
	}

	// 半開区間 [0, k) の合計を返す
	T sum(int k) {
		T result = 0;
		for (int i=k-1; i>0; i -= (i & -i)) {
			result += nodes[i];
		}

		return result;
	}

	// 半開区間 [s, t) の合計を返す
	T sum(int s, int t) {
		return sum(t) - sum(s);
	}
};

// 数列Xの転倒数を求める
ll count_inversions(vector<ll>& X) {
	int N = X.size();
	BIT<ll> bit(N+1); // ひとつ余分に確保
	unordered_map<ll, int> X_to_sorted_idx;

	vector<ll> X_sorted = X;
	sort(X_sorted.begin(), X_sorted.end());

	for (int i=0; i<N; i++) {
		if (! X_to_sorted_idx[X_sorted[i]]) X_to_sorted_idx[X_sorted[i]] = i + 1; // 1-idx
	}

	ll result = 0;

	for (int i=0; i<N; i++) {
		result += bit.sum(X_to_sorted_idx[X[i]] + 1, N+2);
		bit.add(X_to_sorted_idx[X[i]], 1);

	}

	return result;
}

int main() {
	ll N, K;
	cin >> N >> K;

	vector<ll> A(N);
	vector<ll> B(N*2);

	for (int i=0; i<N; i++) {
		cin >> A[i];
		B[i] = A[i];
		B[i+N] = A[i];
	}

	ll A_inv = count_inversions(A);
	ll B_inv = count_inversions(B);

	ll ans = ((A_inv * K) % MOD + ((B_inv - A_inv * 2) * (K * (K-1) / 2 % MOD)) % MOD) % MOD;

	cout << ans << endl;

	return 0;
}
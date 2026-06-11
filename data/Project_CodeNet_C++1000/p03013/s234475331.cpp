#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> dp(N + 1);
	dp[0] = 1;
	unordered_set<int> a;
	int n;
	for (int i = 0; i < M; i++) {
		cin >> n;
		a.insert(n);
	}
	for (int i = 0; i < N; i++) {
		if (a.count(i)) continue;
		for (int j = 1; j <= 2; j++) {
			if (i + j > N) break;
			if (a.count(i + j)) continue;
			dp[i + j] = (dp[i + j] + dp[i]) % 1000000007;
		}
	}
	cout << dp[N] << endl;
}
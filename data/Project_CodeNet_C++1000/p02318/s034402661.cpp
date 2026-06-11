#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct LevenshteinDistance {
	static constexpr T INF = numeric_limits<T>::max();
	const T costInsert, costErase, costReplace;
	LevenshteinDistance(T i, T e, T r) :
		costInsert(i),
		costErase(e),
		costReplace(r)
		{}
	T distance(string& s1, string& s2){
		int n1 = s1.size(), n2 = s2.size();
		// dp[i][j]:=s1のi文字目までとs2のj文字目までの距離
		vector<vector<T>> dp(n1 + 1, vector<T>(n2 + 1, INF));
		for(int i = 0; i <= max(n1, n2); ++i) {
			if(i <= n1) dp[i][0] = (T)i * costErase;
			if(i <= n2) dp[0][i] = (T)i * costInsert;
		}
		for(int i = 1; i <= n1; ++i) {
			for(int j = 1; j <= n2; ++j) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + costInsert);
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + costErase);
				dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : costReplace));
			}
		}
		return dp[n1][n2];
	}
};

int main() {
	LevenshteinDistance<int> ld(1, 1, 1);
	string s1, s2; cin >> s1 >> s2;
	cout << ld.distance(s1, s2) << endl;
	return 0;
}


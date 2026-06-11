#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 998244353

using namespace std;
using ll = long long;
using ldb = long double;

ll mod_add(ll a, ll b) {
	return (a % DIV + b % DIV) % DIV;
}

ll mod_mul(ll a, ll b) {
	return ((a % DIV) * (b % DIV)) % DIV;
}

int main() {
	int N, S; cin >> N >> S;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	vector<vector<ll>> dp(N + 1, vector<ll>(S + 1));
	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= S; j++) {
			//not take
			dp[i + 1][j] = mod_add(dp[i+1][j],mod_mul((ll)2,dp[i][j]));
			//take
			if (j + a[i] <= S)
			dp[i+1][j+a[i]]= mod_add(dp[i + 1][j+a[i]], dp[i][j]);
		}
	}
	cout << dp[N][S] << endl;
}
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, M; cin >> N >> M;
	vector<ll> s(N+1), t(M+1);
	for (int i = 1; i <= N; i++) {
		cin >> s[i];
	}

	for (int i = 1; i <= M; i++) {
		cin >> t[i];
	}

	ll dp[2005][2005]={0};
	ll sum[2005][2005]={0};
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (s[i] == t[j])
				dp[i][j] = (sum[i - 1][j - 1] + 1) % DIV;
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + dp[i][j];
			sum[i][j] = (sum[i][j] + DIV) % DIV;
		}
	}

	cout << (sum[N][M] + 1 + DIV) % DIV << endl;
}

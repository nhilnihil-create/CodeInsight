#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	string L;
	cin >> L;

	int N = L.size();
	vector<vector<ll>> dp(N + 1, vector<ll>(2));

	dp[0][0] = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <=1 ; j++) {
			if (j == 1) {
				dp[i + 1][j] += 3*dp[i][j];
				dp[i + 1][j] %= DIV;
			}
			else {
				if (L[i] == '1') {
					dp[i + 1][0] += 2*dp[i][j];
					dp[i + 1][0] %= DIV;
					dp[i + 1][1] += dp[i][j];
					dp[i + 1][1] %= DIV;
				}
				else {
					dp[i + 1][j] += dp[i][j];
					dp[i + 1][j] %= DIV;
				}
			}
		}
	}

	cout << (dp[N][0] + dp[N][1])%DIV << endl;
}

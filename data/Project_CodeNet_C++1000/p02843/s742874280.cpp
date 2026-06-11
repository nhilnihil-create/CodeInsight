#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int X; cin >> X;
	vector<ll> dp(X + 1);
	dp[0] = 1;
	for (int i = 0; i < X; i++) {
		for (int j = 0; j <= 5; j++) {
			if (i + 100 + j > X)break;
			dp[i + 100 + j] += dp[i];
		}
	}
	cout << (dp[X] ? 1 : 0) << endl;
}

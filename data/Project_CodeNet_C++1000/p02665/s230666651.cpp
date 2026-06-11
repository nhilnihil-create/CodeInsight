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
#define TE 2e6+5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N;
	vector<ll> A(N + 1);
	for (int i = 0; i <= N; i++) {
		cin >> A[i];
	}

	vector<pair<ll, ll>> le(N + 1);
	le[N].first = A[N], le[N].second = A[N];
	for (int i = N - 1; i >= 0; i--) {
		le[i].first = A[i] + (le[i + 1].first + 1) / 2;
		le[i].second = A[i] + le[i + 1].second;
		//printf("le[%d].first=%lld le[%d].second=%lld\n", i, le[i].first, i, le[i].second);
	}

	vector<ll> dp(N + 1);
	bool flag = true;
	if (le[0].first <= 1 && 1 <= le[0].second) dp[0] = 1;
	else flag = false;

	ll cnt = 0;	
	for (int i = 1; i <= N && flag; i++) {
		//printf("i=%d \n", i);
		if (2 * (dp[i - 1] - A[i - 1]) < le[i].first) {
			flag = false;
		}
		dp[i] = min(2 * (dp[i - 1] - A[i - 1]), le[i].second);
		cnt += dp[i];
		//printf("dp[%d]=%lld\n", i, dp[i]);
	}

	if (!flag)cout << -1 << endl;
	else cout << cnt + 1 << endl;
}


/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012, M = 10123;
int a[N], b[N], dp[M];

int32_t main(){
	int h, n;
	cin >> h >> n;
	for (int i = 0; i < M; i++) {
		dp[i] = 1000000000;
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		for (int j = 0; j < M; j += a[i]) {
			dp[j] = min(dp[j], (j / a[i]) * b[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < M - a[i]; j++) {
			dp[j + a[i]] = min(dp[j + a[i]], dp[j] + b[i]);
		}
	}
	int mn = 1000000000;
	for (int i = h; i < M; i++) {
		mn = min(mn, dp[i]);
	}
	cout << mn;
}

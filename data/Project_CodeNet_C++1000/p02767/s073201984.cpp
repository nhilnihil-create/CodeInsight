// #include <bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define exf(x)	 for(auto&& tmp : x) { cout << tmp << endl; }	// 拡張for
#define PI 3.14159265358979323846264338327950288
const int MOD{ int(1e9 + 7) };	// = 1000000007
const int inf{ 2100000000 };	// = 2100000000 (MAX:2147483647)
typedef long long ll;
using namespace std;

// -------------------------------------------------- //
// ------------------ ここから本編 ------------------ //
// -------------------------------------------------- //

int main(void) {

	int N; cin >> N;
	vector<int> x(N);
	int MIN = inf, MAX = 0;
	rep(i, N) {
		cin >> x[i];
		MIN = min(MIN, x[i]);
		MAX = max(MAX, x[i]);
	}

	ll ans = inf;

	for (int i = MIN; i <= MAX; i++) {
		ll sum = 0;
		rep(j, N) sum += (x[j] - i) * (x[j] - i);
		ans = min(ans, sum);
	}

	cout << ans << endl;
	return 0;
}

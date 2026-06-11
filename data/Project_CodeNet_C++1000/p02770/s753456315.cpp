//方針変えたら(たぶん)自明で草
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <tuple>
#define rep(i, n) for(i = 0; i < n; i++)
#define int long long
using namespace std;

int k, q;
int d[5000];

int solve(int n, int x, int m) {
	int i;
	
	int s = x % m, ng = 0;
	rep(i, k) {
		int e = d[i] % m;
		int cnt;
		if (e == 0) { e = m; }
		if (n - 2 - i < 0) { cnt = 0; }
		else { cnt = (n - 2 - i) / k + 1; }
		s += e * cnt;
	}
	ng += s / m;
	return n - 1 - ng;
}

signed main() {
	int i;
	int n, x, m;

	cin >> k >> q;
	rep(i, k) cin >> d[i];
	
	rep(i, q) {
		cin >> n >> x >> m;
		int ans = solve(n, x, m);
		cout << ans << endl;
	}
	return 0;
}
#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>

using namespace std;
typedef long long ll;
typedef double db;
#define inf 0x3f3f3f3f
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int ll
int a[2123];
signed main() {
	int n, i, t, j;
	cin >> n;
	for (i = 0; i < n; ++i)cin >> a[i];
	sort(a, a + n);
	a[n] = inf;
	int ans = 0;
	for (i = 0; i < n; ++i) {
		for (j = i+1; j < n; ++j) {
			int* tt = lower_bound(a + j + 1, a + n + 1, a[i] + a[j]);
			int t = tt - a;
			ans += (t - j - 1);
		}
	}
	cout << ans << endl;
	return 0;
}

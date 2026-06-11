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
ll a[312345];
ll b[312345];
ll c[312345];//输出
ll d[312345];//前缀和
ll n, m;
ll solve(ll t) {	//t 一次的数量
	ll ans = 0, i;
	t = m - t + 1;//从t到m取牌
	ans = d[t - 1];
	ll left = a[t], right = a[m] + ans;
	while (left < right) {
		ll mid = left + right+1 >> 1;//mid 最大次数
		ll* tt = lower_bound(a + t, a + m + 1, mid);
		ll x = tt - a;//坐标值
		ll y = x - t;//不够个数
		ll z = d[x - 1] - d[t - 1];//已有数量
		z = mid * y - z;//缺口
		if (z > ans)right = mid - 1;
		else left = mid;
	}
	return left;
}
signed main() {
	ll i, t;
	cin >> n;
	for (i = 0; i < n; ++i)cin >> b[i];
	sort(b, b + n);
	a[1] = 1;
	ll cnt = 1;
	for (i = 1; i < n; ++i) {
		if (b[i] == b[i - 1])++a[cnt];
		else {
			a[++cnt] = 1;
		}
	}
	m = cnt;
	sort(a + 1, a + m + 1);
	a[m + 1] = inf;
	for (i = 1; i <= m; ++i) {
		d[i] = a[i] + d[i - 1];
	}
	//for (i = 1; i <= m; ++i)cout << d[i] << endl;
	for (i = m + 1; i <= n; ++i)c[i] = 0;
	for (i = 1; i <= m; ++i) {
		c[i] = solve(i);
	}
	for (i = 1; i <= n; ++i)cout << c[i] << " ";
	cout << endl;
}
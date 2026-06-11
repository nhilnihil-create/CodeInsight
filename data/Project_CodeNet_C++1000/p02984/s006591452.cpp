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
ll a[212345];
ll b[212345];
signed main() {
	ll n, i, t;
	cin >> n;
	for (i = 1; i <= n; ++i)cin >> a[i];
	b[2] = a[1] + a[2];
	for (i = 3; i <= n; ++i) {
		if (i & 1)b[2] -= a[i];
		else b[2] += a[i];
	}
	a[1] -= b[2] / 2, a[2] -= b[2] / 2;
	for (i = 3; i <= n; ++i) {
		b[i] = a[i - 1] * 2;
		a[i] -= a[i - 1];
	}
	b[1] = a[1] + a[n];
	for (i = 1; i <= n; ++i)cout << b[i] << " ";
	cout << endl;
	return 0;
}
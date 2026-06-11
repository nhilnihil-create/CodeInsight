#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 2005
#define PR pair<ll,ll>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll n, ans, d[N][N];
pair<ll, ll> a[N];
int main() {
	ll i, j, k;
	cin >> n;
	for(i=0; i<n; i++) scanf("%lld", &a[i].F), a[i].S = i;
	sort(a, a+n, greater<PR>());
	for(i=0; i<n; i++) for(j=0; j<=i; j++) {
		k = n - (i-j);
		d[j][k-1] = max(d[j][k-1], d[j][k] + a[i].F * abs(a[i].S - (k-1)));
		d[j+1][k] = max(d[j+1][k], d[j][k] + a[i].F * abs(a[i].S - j));
	}
	for(i=0; i<=n; i++) ans = max(ans, d[i][i]);
	cout << ans;
	return 0;
}
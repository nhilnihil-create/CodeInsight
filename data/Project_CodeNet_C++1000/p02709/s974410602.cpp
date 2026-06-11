#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, dp[2005][2005];
pair <ll, ll> a[2005];

bool cmp (pair <ll, ll> a, pair <ll, ll> b) {
	return (a.first>b.first);
}

ll hitung (ll x, ll y) {
	if (x>n) return 0;
	if (dp[x][y]==-1) {
		ll kiri=hitung(x+1, y+1)+a[x].first*abs(a[x].second-y-1);
		ll kanan=hitung (x+1, y)+a[x].first*abs(a[x].second-(n-x+1+y));
		dp[x][y]=max(kiri, kanan);
	}
	return dp[x][y];
}

int main() {
	cin>>n;
	memset (dp, -1, sizeof(dp));
	for (int i=1; i<=n; i++) {
		cin>>a[i].first;
		a[i].second=i;
	}
	sort (a+1, a+n+1, cmp);
	cout<<hitung(1, 0)<<endl;
}


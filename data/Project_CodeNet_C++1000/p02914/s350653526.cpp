#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int maxV = 90010;
const int maxN = 1e5+10;
const int inf = 0x3f3f3f3f;
const int MOD = 993244853;
const ll INF = 1000000000000000010LL;

const int MAXN = 200010;
const int MAXK = 62;

int n;
ll a[MAXN];

int m;

void solve()
{
	cin >> n;
	ll sum = 0;
	
	for (int i = 1; i <= n; ++ i)
	{
		cin >> a[i];
		sum ^= a[i];
	}
	for (int i = 1; i <= n; ++ i)
		a[i] &= ~sum;
	
	for (int k = MAXK-1; k >= 0; -- k)
	{
		int id = 0;
		for (int i = m+1; i <= n; ++ i)
			if (a[i]>>k&1)
			{
				id = i;
				break;
			}
		if (!id) continue;
		++ m;
		swap(a[m], a[id]);
		for (int i = 1; i <= n; ++ i) if (i != m)
			if (a[i]>>k&1) a[i] ^= a[m];
	}
	
	ll ans = sum;
	
	ll tmp = 0;
	
	for (int i = 1; i <= m; ++ i)
		if ((tmp^a[i]) > tmp) tmp ^= a[i];
	
	ans += tmp*2;
	
	cout << ans << endl;
}

int main() {
	
	solve();
	
	return 0;
}
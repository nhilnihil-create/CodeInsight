#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
const ll LINF = 1e18 + 5;
int n;
ll calcu(ll x)
{
	ll ans = 0;
	while(x>=10)
	{
		ans += x/10;
		x = x/10 + x%10;
	}
	return ans;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
	ll len = 0, cur = 0;
 	for(int i=1;i<=n;i++)
 	{
 		int d1;
		ll c1;
 		cin >> d1 >> c1;
 		len += c1;
 		cur += c1*d1;
 	}
 	len += calcu(cur) - 1;
 	cout << len;
	return 0;
}

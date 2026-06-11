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
const int INF = 0x3f3f3f3f, N = 1e5 + 5;
const ll LINF = 1e18 + 5;
int n, m, v, p;
int a[N];
bool check(int x)
{
	if(a[x]+m<a[p]) return 0;
	int have = p-1+n-x+1;
	if(have>=v) return 1;
	ll need = 0;
	for(int i=p; i<x; i++)
		need += (a[x]+m-a[i]);
	return need>=1ll*(v-have)*m;
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> m >> v >> p;
 	for(int i=1; i<=n; i++) cin >> a[i];
 	sort(a+1, a+n+1);
 	reverse(a+1, a+n+1);
 	int l = p+1, r = n, ans = p;
 	while(l<=r)
 	{
 		int mid = (l+r)>>1;
 		if(check(mid)) l = mid+1, ans = mid;
 		else r = mid-1;
 	}
 	cout << ans;
	return 0;
}

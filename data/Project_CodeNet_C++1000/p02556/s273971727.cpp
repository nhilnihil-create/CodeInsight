#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define rep(i, a, n) for (int i=(a); i<(n); i++)
#define per(i, a, n) for (int i=(a); i>(n); i--)
typedef long long ll;
const int maxn = 2e5+5;
const int mod = 1e9+7;
using namespace std;

ll mi1 = 1e18, mx1 = -1e18, mi2 = 1e18, mx2 = -1e18, mi3 = 1e18, mx3 = -1e18, mi4 = 1e18, mx4 = -1e18;

void solve() {
	ll n,ans=-1e18,x,y; cin >> n;
	for(int i=0; i<n; i++) {
		cin >> x >> y;
		mi1 = min(mi1, -x+y);
		mx1 = max(mx1, -x+y);
		mi2 = min(mi2, x-y);
		mx2 = max(mx2, x-y);
		mi3 = min(mi3, x+y);
		mx3 = max(mx3, x+y);
		ans = max({mx1+mx2, -mi1-mi2, mx3 - mi3});
	}
	cout << ans << '\n';
}

int main(int argc, char * argv[]) 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef DEBUG
	freopen("C:/Users/Fish_Brother/Desktop/in", "r", stdin);
	//freopen("C:/Users/Fish_Brother/Desktop/out", "w", stdout);
#endif

	//int t; cin >> t; while(t--)
	solve();

    return 0;
}
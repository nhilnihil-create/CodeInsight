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
ll t1, t2, a1, a2, b1, b2;
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> t1 >> t2;
 	cin >> a1 >> a2;
 	cin >> b1 >> b2;
	ll p = a1*t1 - b1*t1, q = a2*t2 - b2*t2;
	if(p>0) p *= -1, q *= -1, swap(a1,b1), swap(a2,b2);
	if(p+q<0) cout << 0;
	else if(p+q==0) cout << "infinity";
	else 
	{
		ll ans = 2*((-p)/(p+q)) + ((-p)%(p+q) ? 0 : -1) + 1;
		cout << ans;
	}
	return 0;
}

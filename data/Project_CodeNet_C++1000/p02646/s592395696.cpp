#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

int main() {
	ll a, v, b, w, t;
	cin >> a >> v >> b >> w >> t;
	ll mid = abs(b-a);
	ll ts = abs(w-v);
	if(w-v >= 0){
		puts("NO");
		return 0;
	}
	if(ts*t >= mid) puts("YES");
	else puts("NO");
 	return 0;
}
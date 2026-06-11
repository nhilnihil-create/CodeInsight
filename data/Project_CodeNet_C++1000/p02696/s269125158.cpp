#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
const ll MOD = 1000000007;
const ll INF = 1e18;
#define REP(i, n) for(int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main(){
	ll a, b, n; cin >> a >> b >> n;
	ll x=min(n,b-1);
	ll ans=(a*x)/b-a*(x/b);
	cout << ans << endl;
	return 0;
}
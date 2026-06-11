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
	ll n;
	cin >> n;
	vector<ll> a;
	ll j = 1;
	rep(i,n){
		ll A;
		cin >> A;
		if(j==A){
			a.push_back(A);
			j++;
		}
	}
	if(a.size() == 0) cout << -1 << endl;
	else cout << n-a.size() << endl;
 	return 0;
}
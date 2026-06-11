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
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
int main() {
	ll n, ans=0;
	cin >> n;
	vector<ll> a(n+1, 1);
	for (ll i = 2; i < n+1; i++)
	{
		for(ll j=i; j<n+1; j+=i){
			a[j]++;
		}
	}
	loop(k, 1, n+1){
		ans+=k*a[k];
	}
	cout << ans << endl;

	return 0;
}

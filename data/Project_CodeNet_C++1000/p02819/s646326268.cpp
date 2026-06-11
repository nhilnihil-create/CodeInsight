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
	ll x;
	cin >> x;
	vector<ll> a(3*x);
	loop(i, 2, 3*x){
		if(a[i]==0 && i>=x){
			cout << i << endl;
			return 0;
		}
		for(ll j=i; j<3*x; j+=i){
			a[j]++;
		}
	}

	return 0;
}

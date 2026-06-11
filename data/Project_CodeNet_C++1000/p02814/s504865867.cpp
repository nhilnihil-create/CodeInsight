#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return a / g * b;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	ll m;
	cin >> n >> m;
	vector<ll> a(n);
	rep(i,n){
		cin >> a[i];
		a[i] /= 2;
	}
	ll c = 0, A = a[0];
	while(A%2 == 0){
		++c;
		A /= 2;
	}
	ll l = a[0];
	rep(i,n){
		l = lcm(l, a[i]);
		A = a[i];
		ll cnt = 0;
		while(A%2 == 0){
			++cnt;
			A /= 2;
		}
		if(cnt != c){
			cout << 0 << endl;
			return 0;
		}
		a[i] = A;
	}
	ll ans = (m / l + 1) / 2;
	cout << ans << endl;
	return 0;
}

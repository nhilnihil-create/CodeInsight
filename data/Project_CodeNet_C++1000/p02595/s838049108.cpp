#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<int,int>;



int main() {
	
	
	ll n, d; cin >> n >> d;
	ll D = d * d;

	// cout << d*d << endl;
	
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	
	
	int ans = 0;
	rep(i,n){
		ll d2 = a[i]*a[i] + b[i]*b[i];
		if(d2 <= D) ans++;
	}
	
	cout << ans << endl;
	
	return 0;
}

#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 2e9;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	bool pos = false, neg = false;
	vector<ll> a(n);
	ll sum = 0, mi = INF;
	rep(i,n){
		cin >> a[i];
		if(a[i] >= 0){
			pos = true;
			chmin(mi, a[i]);
			sum += a[i];
		}
		if(a[i] <= 0){
			neg = true;
			chmin(mi, -a[i]);
			sum -= a[i];
		}
	}
	sort(a.rbegin(), a.rend());
	ll ans = sum;
	if(!pos || !neg) ans -= 2 * mi;
	cout << ans << endl;
	ll x = a[0], y = a[n-1];
	for(int i = 1; i < n-1; ++i){
		if(a[i] < 0){
			cout << x << " " << a[i] << endl;
			x -= a[i];
		}
		else{
			cout << y << " " << a[i] << endl;
			y -= a[i];
		}
	}
	cout << x << " " << y << endl;
	return 0;
}
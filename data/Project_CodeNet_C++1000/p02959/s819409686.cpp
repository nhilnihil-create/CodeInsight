#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> a(n+1);
	rep(i,n+1) cin >> a[i];
	ll ans = 0;
	rep(i,n){
		ll b;
		cin >> b;
		if(b >= a[i]){
			ans += a[i];
			b -= a[i];
		}
		else{
			ans += b;
			b = 0;
		}
		if(b >= a[i+1]){
			ans += a[i+1];
			a[i+1] = 0;
		}
		else{
			ans += b;
			a[i+1] -= b;
		}
	}
	cout << ans << endl;
	return 0;
}

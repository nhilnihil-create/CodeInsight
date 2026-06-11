#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	rep(i,n){
		cin >> a[i];
		--a[i];
	}
	rep(i,n) cin >> b[i];
	rep(i,n-1) cin >> c[i];
	int ans = 0;
	rep(i,n){
		ans += b[a[i]];
		if(i+1 < n && a[i+1] == a[i]+1) ans += c[a[i]];
	}
	cout << ans << endl;
	return 0;
}
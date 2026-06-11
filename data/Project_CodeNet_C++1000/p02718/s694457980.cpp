#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n);
	ll sum = 0;
	rep(i,n){
		cin >> a[i];
		sum += a[i];
	}
	int ans = 0;
	rep(i,n){
		if(4*m*a[i] >= sum) ++ans;
	}
	if(ans >= m) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
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
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ma, mb, ans;
	if(n%2 == 1){
		ma = a[n/2];
		mb = b[n/2];
		ans = mb - ma + 1;
	}
	else{
		ma = (a[(n-1)/2] + a[n/2]);
		mb = (b[(n-1)/2] + b[n/2]);
		ans = mb - ma + 1;
	}
	cout << ans << endl;
	return 0;
}
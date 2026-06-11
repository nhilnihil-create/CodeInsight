#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, int> LP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	vector<int> a(n+1);
	rep(i,n) cin >> a[i];
	a[n] = k + a[0];
	int mx = 0;
	rep(i,n) chmax(mx, a[i+1] - a[i]);
	int ans = k - mx;
	cout << ans << endl;
	return 0;
}
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
	int n;
	cin >> n;
	vector<int> l(n);
	rep(i,n) cin >> l[i];
	sort(l.begin(), l.end());
	ll ans = 0;
	rep(i,n-2){
		for(int j = i+1; j < n-1; ++j){
			int idx = lower_bound(l.begin(), l.end(), l[i]+l[j]) - l.begin();
			ans += (ll)(idx - j - 1);
		}
	}
	cout << ans << endl;
	return 0;
}

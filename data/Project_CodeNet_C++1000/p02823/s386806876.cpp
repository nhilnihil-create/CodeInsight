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
	ll n, a, b;
	cin >> n >> a >> b;
	ll ans = 1e18;
	if((b-a)%2 == 0) ans = (b - a) / 2;
	else{
		ll ans1 = a + ((b-a) - 1) / 2;
		ll ans2 = (n-b+1) + (n - (a+(n-b+1))) / 2;
		ans = min(ans1, ans2);
	}
	cout << ans << endl;
	return 0;
}

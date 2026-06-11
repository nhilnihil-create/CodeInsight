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
	ll ans;
	if((b-a)%2 == 0) ans = (b-a)/2;
	else{
		ll ans1 = a;
		ll A = 1, B = b - a;
		ans1 += (B - A) / 2;
		ll ans2 = n - b + 1;
		B = n; A = a + (n - b + 1);
		ans2 += (B - A) / 2;
		ans = min(ans1, ans2);
	}
	cout << ans << endl;
	return 0;
}

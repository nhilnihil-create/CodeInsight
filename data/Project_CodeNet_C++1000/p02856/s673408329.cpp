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
	int m;
	cin >> m;
	ll sum = 0, ans = -1;
	rep(i,m){
		ll a, b;
		cin >> a >> b;
		ans += b;
		sum += a * b;
	}
	ans += (sum - 1LL) / 9LL;
	cout << ans << endl;
	return 0;
}
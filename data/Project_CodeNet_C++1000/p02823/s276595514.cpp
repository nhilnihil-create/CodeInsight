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
	if((b-a)%2 == 0){
		ans = (b - a) / 2;
	}
	else{
		ll c, d;
		if(n-b <= a-1){
			d = n;
			c = a + (n - b) + 1;
			ans = (n - b + 1) + (d - c) / 2;
		}
		else{
			c = 1;
			d = b - a;
			ans = a + (d - c) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}
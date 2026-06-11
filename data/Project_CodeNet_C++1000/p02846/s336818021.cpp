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
	ll t1, t2, a1, a2, b1, b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	ll p = (a1 - b1) * t1;
	ll q = (a2 - b2) * t2;
	if(p > 0){
		p *= -1;
		q *= -1;
	}
	if(p+q < 0) cout << 0 << endl;
	else if(p+q == 0) cout << "infinity" << endl;
	else{
		ll s = (-p) / (p+q);
		ll t = (-p) % (p+q);
		if(t != 0) cout << (s*2 + 1LL) << endl;
		else cout << (s*2) << endl;
	}
	return 0;
}
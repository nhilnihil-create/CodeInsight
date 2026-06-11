#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int f[10000001];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll ans = 0;
	for(ll i = 1; i <= n; ++i){
		for(int j = i; j <= n; j+=i){
			++f[j];
		}
		ans += i * f[i];
	}
	cout << ans << endl;
	return 0;
}
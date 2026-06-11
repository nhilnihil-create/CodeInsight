#include "bits/stdc++.h"
//#include "atcoder/all"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
//using namespace atcoder;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int l, r, d;
	cin >> l >> r >> d;
	int ans = 0;
	for(int i = l; i <= r; ++i){
		if(i%d == 0) ++ans;
	}
	cout << ans << endl;
	return 0;
}

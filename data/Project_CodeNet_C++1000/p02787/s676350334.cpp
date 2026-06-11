#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

//#include "atcoder/all"
//using namespace atcoder;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int h, n;
	cin >> h >> n;
	vector<int> dp(h+1, 1e9);
	dp[0] = 0;
	rep(i,n){
		int a, b;
		cin >> a >> b;
		rep(j,h+1){
			int nj = min(j+a, h);
			chmin(dp[nj], dp[j] + b);
		}
	}
	cout << dp[h] << endl;
	return 0;
}
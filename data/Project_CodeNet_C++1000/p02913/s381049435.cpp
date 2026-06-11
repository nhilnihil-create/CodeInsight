#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dp[5005][5005];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	for(int i = n-1; i >= 0; --i){
		for(int j = n-1; j >= 0; --j){
			if(s[i] == s[j]) dp[i][j] = dp[i+1][j+1] + 1;
		}
	}
	int ans = 0;
	for(int i = 0; i < n; ++i){
		for(int j = i+1; j < n; ++j){
			int cmp = min(dp[i][j], j-i);
			chmax(ans, cmp);
		}
	}
	cout << ans << endl;
	return 0;
}

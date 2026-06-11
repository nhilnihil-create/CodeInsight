#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool dp[100500];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x;
	cin >> x;
	dp[0] = true;
	rep(i,x){
		if(dp[i]){
			rep(j,6){
				dp[i+100+j] = true;
			}
		}
	}
	if(dp[x]) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}
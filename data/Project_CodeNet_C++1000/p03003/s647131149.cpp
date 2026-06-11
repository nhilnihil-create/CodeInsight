#include<bits/stdc++.h>

using namespace std;

#define INF 1000000007
#define LINF (1LL << 62)

typedef long long i64;
typedef pair<i64,i64> P;

inline i64 mod(i64 a, i64 m) { return (a % m + m) % m; }

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }



int n, m, a[2020], b[2020];
i64 dp[2020][2020];
void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	
	for(int i = 0; i <= n; i++) dp[i][0] = 1;
	for(int i = 0; i <= m; i++) dp[0][i] = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
			if(a[i] != b[j]){
				dp[i+1][j+1] -= dp[i][j];
			}
			dp[i+1][j+1] = mod(dp[i+1][j+1], INF);
		}
	}
	cout << dp[n][m] << endl;
}

int main(){
	std::cin.tie(0);
	std::ios::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while(t--){
		solve();
	}
	
	return 0;
}
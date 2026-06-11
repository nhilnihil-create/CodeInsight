#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<numeric>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl;

using namespace std;

const int INF = 100000000;

int main() {
	int N;
	cin >> N;
	rep(i, N) {
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.size();
		int m = s2.size();
		vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
		dp[0][0] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				if(s1[i-1] == s2[j-1]) {
					dp[i][j] = dp[i-1][j-1] + 1;
				} else {
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}	
			}
		}
		cout << dp[n][m] << endl;
	}
	return 0;
}
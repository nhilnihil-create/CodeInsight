#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<stack>
#include<queue>
#include<sstream>
#include<string>
#include<set>
#include<array>
#include<cassert>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define DUMP(list) cout << "{ "; for(auto nth : list){ cout << nth << " "; } cout << "}" << endl
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i);

using namespace std;

const int MAX_N=101;
const int MAX_W=10001;
const int INF=1<<29;

int dp[MAX_N][MAX_W];

int main(){
	int n,w;
	cin >> n >> w;

	int wait[n],value[n];

	rep(i,n){
		cin >> value[i+1] >> wait[i+1];
	}

	for (int i = 0; i <= w; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= wait[j])
				dp[j][i] = max(dp[j-1][i], dp[j-1][i-wait[j]] + value[j]);
			else
				dp[j][i] = dp[j-1][i];
		}
	}

	cout << dp[n][w] << endl;

}
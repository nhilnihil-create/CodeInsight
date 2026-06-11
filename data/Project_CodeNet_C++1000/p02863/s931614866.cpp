#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <stack>
#include <vector>
#include <set>
#include <tuple>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
const int INF = 1000000000;
const int MOD = 1000000007;
int main(){
	int n,t;
	cin >> n >> t;

	vector<P> ab(n);
	for(int i = 0;i < n;i++){
		int a,b;
		cin >> a >> b;
		ab[i] = P(a,b);
	}

	sort(ab.begin(),ab.end());

	vector<vector<ll>> dp(n+1,vector<ll>(t+1,0));
	//t-1までからは遷移出来る.
	for(int i = 0;i < n;i++){
		int a = ab[i].first;
		int b = ab[i].second;
		for(int j = 0;j <= t;j++){
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			if(j <= t-1)dp[i+1][min(t,j+a)] = max(dp[i+1][min(t,j+a)],dp[i][j]+b);
		}
	}

	cout << dp[n][t] << endl;
}

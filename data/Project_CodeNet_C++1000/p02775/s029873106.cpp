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
const int MOD = 1000000009;
const ll INFL = 1e18;
int dp[1000005][2];
int main(){
	string s;
	cin >> s;
	reverse(s.begin(),s.end());
	s += '0';
	int n = s.size();

	for(int i = 0;i <= n;i++){
		for(int j = 0;j < 2;j++){
			dp[i][j] = INF;
		}
	}

	dp[0][0] = 0;
	for(int i = 0;i < n;i++)for(int j = 0;j < 2;j++){
		int x = s[i] - '0';
		x += j;
		for(int a = 0;a < 10;a++){
			int ni = i+1,nj = 0;
			int b = a-x;
			if(b < 0){
				nj = 1;
				b += 10;
			}
			dp[ni][nj] = min(dp[ni][nj],dp[i][j]+a+b);
		}
	}

	int ans = dp[n][0];
	cout << ans << endl;
	return 0;
}

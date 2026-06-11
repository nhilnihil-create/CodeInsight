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

int dp[100005][2];
//dp[i][0]は一致,dp[i][1]は未満.
int main(){
	string s;
	cin >> s;
	dp[0][0] = 1;

	//aとbのi桁目は(1,1)であってはいけない.
	//a+b=1,a+b=0の場合で場合分けをする.(つまり等しい、小さいは和を見て言っている)
	//桁dpで持ちたいのは,a+bがi桁まで等しい状態かどうかとそれを達成する場合の数がいくつか.
	int n = s.size();
	for(int i = 0;i < n;i++){
		{//a+b=0にするとき.
			if(s[i] == '0'){
				dp[i+1][0] = dp[i][0];//(a,b)=(0,0)しか取り得ない.
				dp[i+1][1] = dp[i][1];
			}
			else{
				dp[i+1][1] = (dp[i][0] + dp[i][1]) % MOD;
			}
		}
		{//a+b=1にするとき (1,0),(0,1)の2通り
			if(s[i] == '0'){//取れないから,手前の場合の数と変わらない.
				dp[i+1][1] += dp[i][1] * 2 % MOD;
				dp[i+1][1] %= MOD;
			}
			else{
				dp[i+1][0] += dp[i][0] * 2 % MOD;
				dp[i+1][1] += dp[i][1] * 2 % MOD;
				dp[i+1][0] %= MOD;
				dp[i+1][1] %= MOD;
			}
		}
	}

	int ans = (dp[n][0] + dp[n][1]) % MOD;
	cout << ans << endl;
}

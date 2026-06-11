//abc129_e.cpp
//Tue Jun  2 23:00:20 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	string l;
	cin >> l;

	ll dp[2][l.size()+1];
	for (int i=0;i<2;i++){
		for (int j=0;j<l.size()+1;j++){
			dp[i][j] = 0;
		}
	}

	dp[0][0] = 1;
	dp[1][0] = 0;

	for (int i=1;i<l.size()+1;i++){
		if (l[i-1]=='1'){
			dp[0][i] = dp[0][i-1]*2%MOD;
			dp[1][i] = (dp[1][i-1]*3+dp[0][i-1])%MOD;
		}else {
			dp[0][i] = dp[0][i-1]%MOD;
			dp[1][i] = dp[1][i-1]*3%MOD;
		}
	}

	ll ans = (dp[0][l.size()]+dp[1][l.size()])%MOD;
	cout << ans << endl;
//	printf("%.4f\n",ans);
}
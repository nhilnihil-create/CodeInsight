//g++ -std=c++14 test.cpp -o test.out

#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <stack>
#include <map> 
#include <unordered_map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
//const LL mod = 1000000007ll;
const int mod_int = 1000000007;

const LL mod = 998244353ll;

LL N,S;
LL A[3000];

LL ans = 0;

void solve(){
	vector<vector<LL>> dp(N+1,vector<LL>(S+1,0));
	dp[0][0] = 1;
	//ばらまく
	for(int i=0;i<N;i++){
		for(int j=0;j<=S;j++){
			dp[i+1][j] = (dp[i+1][j] + dp[i][j]*2LL)%mod;
			if(j+A[i]<=S) dp[i+1][j+A[i]] = (dp[i+1][j+A[i]]+dp[i][j])%mod;
		}
	}
	ans = dp[N][S];
}

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}
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
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

LL N;
LL A[80];

LL ans = 0;

void solve(){
	//i-1日目に
	//株を全部売却した時の
	//所持金の最大値をdp[i]とする
	vector<LL> dp(N+1,0);
	dp[0] = 1000;
	//ばらまくイメージ
	//i+1日目になった時点での所持金の最大値を求める
	for(int i=0;i<N;i++){
		//最後に売った日付がj日目の時を考える
		for(int j=0;j<=i;j++){
			//j~i日目のうち最も株価が安い日に所持金を目一杯使って買っておく
			LL stock_minimum = INF;
			for(int k=j;k<=i;k++) stock_minimum = min(stock_minimum,A[k]);
			dp[i+1] = max(dp[i+1],dp[j]/stock_minimum*A[i] + dp[j]%stock_minimum);
		}
	}
	ans = dp[N];
}

int main(){
    cin >> N;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}
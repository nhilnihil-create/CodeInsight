//g++ -std=c++14 test.cpp -o test.out
//問題URL
//https://atcoder.jp/contests/abc169/tasks/abc169_f

//参考：
//https://note.com/tanon_cp/n/neda8607cfa7b#5FTIT

//新たに出てきたものを使う、使わないで分岐するのがdpの基本かも

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
 
#define LL unsigned long long int
const LL INF = (1LL<<60);
const int INF_INT = 2147483647-1e6-1;
//const LL mod = 1000000007ll;
const int mod_int = 1000000007;

const LL mod = 998244353ll;

LL N,S;
LL A[3000];

LL ans = 0;

void solve(){
	vector<vector<LL>> dp(N+1,vector<LL>(3001,0));
	dp[0][0] += 1LL;
	//ばらまく
	for(int i=0;i<N;i++){
		for(int j=0;j<=3000;j++){
			if(dp[i][j]==0) continue; 
			//末尾に新しく出現した数をつけるかつけないかでまず*2通り
			//(末尾に出現した数を使わないような、条件を満たす数列を含む数列の数)
			dp[i+1][j] = (dp[i+1][j] + 2*dp[i][j])%mod; 
			if(j+A[i]<=3000){
				//末尾に出現した数を使って和がj+A[i]になるようなものを作る
				//(末尾に出現した数を絶対に使うような、条件を満たす数列を含む数列の数)
				dp[i+1][j+A[i]] = (dp[i+1][j+A[i]] + dp[i][j])%mod;
			}
		}
	}
	// for(int i=0;i<=N;i++){
	// 	cout << "i=" << i << ":";
	// 	for(int j=0;j<=S;j++) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	ans = dp[N][S];
}

int main(){
    cin >> N >> S;
    for(int i=0;i<N;i++) cin >> A[i];

    solve();

    cout << ans << endl;
    return 0;
}
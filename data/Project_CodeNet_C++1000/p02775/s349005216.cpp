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
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
const int mod_int = 1000000007;

string S;

LL ans = INF;

void solve(){
    //解法：
    //A - N = B となるようなA,Bを決めて、
    //Aの各桁を足した数＋Bの各桁を足した数
    //の最小値を求める
    //Aを決めれば自動的にBも決まる

    //Aの桁数＝Sの桁数+1となる場合があるのでそれを考慮して
    //入力された数の頭の桁に0を追加しておく
    S='0'+S;
    reverse(S.begin(),S.end());//文字列Sを反転
    int n = S.size();//Sが何桁の数なのかを保管
    //下からi桁目まで見て、繰り下がりがj(0 or 1)のときの
    //使う紙幣の枚数の最小値をdp[i][j]とおく
    vector<vector<LL>> dp(n+1,vector<LL>(2,INF));
    //0桁決めた状態では繰り下がりは0
    dp[0][0] = 0;
    //下からi桁目を見る
    //配るイメージのDP
    for(int i=0;i<n;i++){
        //j=0なら繰り下がりなし
        //j=1なら繰り下がりあり
        for(int j=0;j<2;j++){
            int x = S[i] - '0';//今見ている数
            x += j;//jくりさがる
            for(int a=0;a<10;a++){//aをAのi桁目であると仮定する
                int nj=0;//繰り下がりがあるなら1にする
                int b = a-x;//これが負＝くり下がりが発生
                if(b<0){
                    nj = 1;
                    b += 10;
                }
                dp[i+1][nj] = min(dp[i+1][nj],dp[i][j]+a+b);
            }
        }
    }
    ans = dp[n][0];
}
 
int main(){
	cin >> S;
 
	solve();

	cout << ans << endl;
	return 0;
}
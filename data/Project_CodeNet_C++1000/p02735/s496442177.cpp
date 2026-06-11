/*#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>

#include <boost/rational.hpp>
*/
#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define repr4(i,s,n) for(ll i = (n);i>=(s);i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
using Graphw = vector<vector<pair<ll,ll>>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;
#define MOD 1000000007;
/*
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部長が32の浮動小数点数型
using Real32 = mp::number<mp::cpp_dec_float<32>>;
// 仮数部長が1024の浮動小数点数型
using Real1024 = mp::number<mp::cpp_dec_float<1024>>;
// 有理数型
using Rat = boost::rational<Bint>;
*/


int main(){
int H,W;
cin>>H>>W;
char grid[H][W];
rep(i,H){
    rep(j,W){
        cin>>grid[i][j];
    }
}
int dp[H][W];
if(grid[0][0]=='.'){
dp[0][0]=0;
}
else{
    dp[0][0]=1;
}
rep(i,H){
    rep(j,W){
        if((i==0)&&(j==0))continue;
        else if(i==0){
            if(grid[i][j-1]!=grid[i][j]){
            dp[i][j]=dp[i][j-1]+1;
            }
            else{
                dp[i][j]=dp[i][j-1];
            }
        }
        else if(j==0){
            if(grid[i-1][j]!=grid[i][j]){
                dp[i][j]=dp[i-1][j]+1;

            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
        else{
            dp[i][j]=min(dp[i-1][j]+(grid[i-1][j]!=grid[i][j]),dp[i][j-1]+(grid[i][j-1]!=grid[i][j]));

        }
    }
}
cout<<(dp[H-1][W-1]+(grid[H-1][W-1]=='#'))/2<<endl;

return 0;
}
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
const int mod = 1000000007;




int main() {

string S;
cin>>S;
int table[12];
table[0]=1;

rep2(i,1,12){
table[i]=(table[i-1]*10)%13;
}
ll dp[S.size()][13];
rep(i,S.size()){
  rep(j,13){
    dp[i][j]=0;
  }
}
if(S[S.size()-1]=='?'){
  rep(i,10){
    dp[0][i]=1;
  }

}
else{
rep(i,13){
if(i==S[S.size()-1]-'0'){
dp[0][i]=1;
}

}
}


rep2(i,1,S.size()){
if(S[S.size()-i-1]=='?'){
  rep(j,10){
    rep(k,13){
      dp[i][(table[i%12]*j+k)%13]+=dp[i-1][k];
      dp[i][(table[i%12]*j+k)%13]%=mod;
      
      
    }
    
  }
}
else{
  rep(k,13){
    dp[i][(table[i%12]*(S[S.size()-i-1]-'0')+k)%13]+=dp[i-1][k];
    dp[i][(table[i%12]*(S[S.size()-i-1]-'0')+k)%13]%=mod;
  }
}
}

cout<<dp[S.size()-1][5]<<endl;
return 0;
}
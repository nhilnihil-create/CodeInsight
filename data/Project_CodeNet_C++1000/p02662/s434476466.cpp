#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
#define PI acos(-1)
#define oo LLONG_MAX
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
/*
3 4
2 2 4

DPかMapか

DP
0 1 4+1 3
      うつして、0を2倍して、DP+A[i]加算して、DPたす
      今とるとき、2^i倍してとる
      0を2倍して、A[i]を加算して、DPの0以外を加算
  0 1 2     3     4 5
0 1 1 2 0 2 4 4 4
1 0 0 0   0
2 0 1 1 2 4 4 4 8 3 6
3 0 0 0   0
4 0 0 0 1 1 1 5 6
5 

14
0 1 2 3
1 1 2 4 
0 0 0 0 
0 1 4 8 
0 0 0 0 
0 1 5 14 


3
1 1 2 4 
0 0 0 0 
0 1 2 2 
0 0 0 0 
0 0 1 3 

7
1 1 2 4 
0 0 0 0 
0 1 3 3 
0 0 0 0 
0 0 3 7 


2 2　と 4
{2,2} {

3をつくるとき。

1,1,1,2

{1,1,1} = 2通り =2^1
{1,2} = 4通り = 4要素のうち2つつかって2つあまってるから2^2

1,1,1,2,5

{1,1,1,5} = 4通り
{1,2,5} = 8通り

*/
ll MOD = 998244353;
vector<vector<ll>> DP(3010, vector<ll>(3010, 0));

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N, S; cin >> N >> S;
  DP[0][0] = 1;
  DP[1][0] = 1;
  for(ll i=2; i<=N; i++)
    (DP[i][0] = DP[i-1][0] * 2) %= MOD;
  for(ll i=1; i <= N; i++){
    ll A; cin >> A;
    //まずコピー
    for(ll j = 1; j < 3001; j++)
      (DP[i][j] += DP[i-1][j]) %= MOD;
    //A加算
    for(ll j = 3001 - A; j >= 0; j--)
      (DP[i][j + A] += DP[i][j]) %= MOD;
    //1個前加算
    for(ll j = 1; j < 3001; j++)
      (DP[i][j] += DP[i-1][j]) %= MOD;
  }
  cout << DP[N][S] <<endl;  

/*rep(j, S+1){
  rep(i, N+1)
    cout<<DP[i][j]<<" ";
  cout<<endl;
}*/
}

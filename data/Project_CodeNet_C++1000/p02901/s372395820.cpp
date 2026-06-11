#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = s; i < (int)(n); i++)
typedef long long ll;
typedef vector<vector<ll>> vvl;
typedef vector<ll> vl;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;
typedef pair<ll,ll> pll;
typedef priority_queue<string> priquest;
typedef priority_queue<string,vector<string>,greater<string>> rpriquest;
ll max(ll x,ll y){
if(x>y)return x;
else return y;
}
ll min(ll x,ll y){
  return x+y-max(x,y);
}

const ll big=1000000007;
int exp(int x,int y){
    if(y==0)return 1;//0^0=1
    if(x==1||x==0)return x;
    if(y%2==1)return (exp(x,y-1)*x);
    int t=exp(x,y/2);
    return (t*t);
}
void chmin(ll a,ll b){
    if(a>b)a=b;
    return;
}

int main(){
  int n,m;cin >> n >> m;
  vector<int> money(m);
  vector<bitset<12>> can(m,bitset<12>(0));
  rep(i,m){
    int b;
    cin >> money[i] >> b;
    rep(j,b){
      int k;cin >> k;k--;
      can[i][k]=1;
    }
  }
  
  //鍵の開いているか否かは2^12通り
  //それをbitで表現してdp
  //dp[i][j]:=(0_indexでの)i-1番までの鍵でjにする時の費用のmin
  //can[s]のbitをkとして
  //dp[i+1][j+k]=min(dp[i+1][j+k],dp[i][j]+money[s])
  //dp[i+1][j]=min(dp[i][j],dp[i+1][j])
  
  vector<vector<ll>> dp(m+1,vector<ll>(exp(2,n),1000000000));
  dp[0][0]=0;
  
  rep(i,m){
    //i番の鍵を使う.dp[i+1][]を更新していく
    rep(j,exp(2,n)){
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
      bitset<12> s(j);
      s =(s|can[i]);//jと新しい鍵で論理和を取る
      int t=s.to_ullong();
      dp[i+1][t]=min(dp[i+1][t],dp[i][j]+money[i]);
    }
  }
  
  if(dp[m][exp(2,n)-1]>=1000000000)cout << -1 << endl;
  else cout << dp[m][exp(2,n)-1] << endl;
}
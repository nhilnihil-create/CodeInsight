#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<int, int> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000

int main() {
  ll dp[1010][10000];
  rep(i,1010){rep(j,10000){dp[i][j]=INF;}}
  int N,M;
  cin>>N>>M;
  vector<ll>key(M);
  vector<ll>money(M);
  rep(i,M){key[i]=0ll;money[i]=0ll;}
  rep(i,M){
    int a,b;
    cin>>a>>b;
    money[i]=a;
    rep(j,b){
      ll c;
      cin>>c;
      c--;
      key[i]+=(1<<c);
    }
  }
  dp[0][0]=0ll;
  ll max=(1<<N);
  rep(i,M){
    rep(j,max){
      dp[i+1][j]=min(dp[i][j],dp[i+1][j]);
      dp[i+1][j|key[i]]=min(dp[i+1][j|key[i]],dp[i][j]+money[i]);
    }
  }
  if(dp[M][max-1]!=INF){
    cout<<dp[M][max-1];
  }
  else{cout<<-1;}
}


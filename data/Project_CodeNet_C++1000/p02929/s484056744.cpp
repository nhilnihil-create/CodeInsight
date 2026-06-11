#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi=vector<int>;
using vvi=vector<vi>;
using vl=vector<ll>;
using vvl=vector<vl>;
using pii = pair<int,int>;
using pli = pair<ll,int>;
using pll = pair<ll,ll>;
using vpii = vector<pii>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define rep(i, n) for(int i=0;i<(int)n;i++)
#define rep2(i, s, n) for(int i=(s);i<(int)n;i++)
int INF=1e9+7;

ll factorial(ll a) {
  if(!a) return 1;
  return a*factorial(a-1)%INF;
}

int main() {
  int N;
  string S;
  cin >> N >> S;
  
  vpii dp(2*N);
  dp[0]=make_pair(1,1);
  bool flag=true;
  rep(i,2*N-1) {
    if(dp[i].second) {
      if(S[i]==S[i+1]) dp[i+1]=make_pair(dp[i].first,0);
      else dp[i+1]=make_pair(dp[i].first+1,1);
    }
    else {
      if(S[i]==S[i+1]) dp[i+1]=make_pair(dp[i].first,1);
      else {
        if(dp[i].first<2) {
          flag=false;
          break;
        }
        dp[i+1]=make_pair(dp[i].first-1,0);
      }
    }
  }
  
  flag=S[0]=='B'&&dp[2*N-1].first==1;
  if(flag) {
    vi pointR, countL(2*N+1);
    rep(i,2*N) {
      countL[i+1]=countL[i];
      if(dp[i].second) pointR.push_back(i);
      else countL[i+1]++;
    }
    ll ans=factorial(N);
    rep(i,N) ans=ans*(N-countL[pointR[N-i-1]]-i)%INF;
    
    cout << ans << endl;
  }
  else cout << 0 << endl;
}
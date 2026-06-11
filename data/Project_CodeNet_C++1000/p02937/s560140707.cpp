#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)1000000000000
int main() {
  string S,T;
  cin>>S>>T;
  ll N=(ll)S.size();
  set<ll>st[26];
  ll dp[26][S.size()];
  rep(i,N){
    st[S[i]-'a'].insert(i);
  }
  rep(i,26){st[i].insert(10000000ll);}
  rep(i,N){rep(j,26){dp[j][i]=INF;}}
  rep(i,26){
    if(st[i].size()==1){continue;}
    rep(j,N){
      auto t=st[i].upper_bound(j);
      if(*t==10000000ll){dp[i][j]=min(dp[i][j],N-j+*begin(st[i]));}
      else{dp[i][j]=min(dp[i][j],(*t)-j);}
    }
  }
  ll ans=-1ll;
  rep(i,T.size()){
    if(st[T[i]-'a'].size()==1){ans=-2;break;}
    ll g=(ans+N)%N;
    ans+=dp[T[i]-'a'][g];
  }
  cout<<ans+1ll;
}

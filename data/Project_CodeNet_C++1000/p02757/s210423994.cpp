#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)100000000000000

int main() {
  ll N;
  cin>>N;
  string S;
  ll P;
  cin>>P>>S;
  if(P==2||P==5){
    ll memo=0ll;
    rep(i,N){
      if((S[i]-'0')%P==0){
        memo+=(i+1);
      }
    }
    cout<<memo<<endl;
    return 0;
  }
  map<ll,ll>mp;
  ll ans=0ll;
  ll sc=0ll;
  mp[0]=1;
  ll tenf=1ll;
  rep(i,N){
    sc=sc+(tenf*(S[N-i-1]-'0'));
    sc%=P;
    tenf=tenf*10ll;
    tenf%=P;
    mp[sc]++;
  }
  for(auto t:mp){
    auto k=t.second;
    ans+=(k*(k-1ll))/2ll;
  }
  cout<<ans<<endl;
}

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
  ll N;
  cin>>N;
  map<int,int>mp;
  ll ans=0ll;
  queue<int>qu[N];
  rep(i,N){
    rep(j,N-1){
      int a;cin>>a;a--;
      qu[i].push(a);
    }
  }
  queue<int>play;
  rep(i,N){
    mp[i]=qu[i].front();
    qu[i].pop();
  }
  rep(i,N){
    int t=mp[i];
    if(mp[t]==i){
      play.push(i);
    }
  }
  
  while(!play.empty()){
    ans++;
    int g=play.size();
    rep(i,g){
      int x=play.front();play.pop();
      if(!qu[x].empty()){mp[x]=qu[x].front();qu[x].pop();}
      else{mp[x]=-1;continue;}
      int t=mp[x];
      if(mp[t]==x){
        play.push(t);
        play.push(x);
      }
    }
  }
  rep(i,N){if(mp[i]!=-1){cout<<-1;return 0;}}
  cout<<ans;
}


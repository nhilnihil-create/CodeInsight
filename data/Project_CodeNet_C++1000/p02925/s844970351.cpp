#include <bits/stdc++.h>
#define pt(sth) cout << sth << "\n"
#define chmax(a, b) {if(a<b) a=b;}
#define chmin(a, b) {if(a>b) a=b;}
#define moC(a, s, b) (a)=((a)s(b)+MOD)%MOD
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
static const ll INF=1e18;
static const ll MAX=101010;
static const ll MOD=1e9+7;

/*
 for(i=0; i<N; i++)
   cin >> a[i];
*/



ll a[1111][1111];

int main(void) {
  ll i, j, k;
  ll N;
  cin >> N;
  
  for(i=0; i<N; i++) {
    for(j=0; j<N-1; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  
  ll pos[1111]={};
  queue<ll> q;
  for(i=0; i<N; i++) q.push(i);
  
  for(ll d=0; d<=N*(N-1)/2; d++) {
    ll used[1111]={};
    ll upd=0;
    
    queue<ll> tq;
    
    while(q.size()) {
      ll u=q.front(); q.pop();
      if(used[u]) continue;
      if(pos[u]==N-1) continue;
      
      ll e=a[u][pos[u]];
      if(used[e]) continue;
      
      if(a[e][pos[e]]==u) {
        used[u]=1; used[e]=1;
        pos[u]++; pos[e]++;
        upd=1;
        tq.push(u); tq.push(e);
      }
    }
    
    queue<ll> ttq;
    while(tq.size()) {
      q.push(tq.front());
      ttq.push(tq.front());
      tq.pop();
    }
    
    
    if(!upd) {
      pt(-1);
      return 0;
    }else {
      ll f=1;
      while(ttq.size()) {
        if(pos[ttq.front()]<N-1) f=0;
        ttq.pop();
      }
      
      if(f) {
        pt(d+1);
        return 0;
      }
    }
    
    
  }
  
  
}


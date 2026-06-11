#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repp(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<double, P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)10000000000000000

int main() {
  int N,K;
  cin>>N>>K;
  int ch=(N-1)*(N-2)/2;
  if(ch<K){cout<<-1;return 0;}
  int g=ch-K;
  queue<P>qu;
  rep(i,N-1){
    qu.push(P(1,i+2));
  }
  int flag=0; 
  repp(i,2,N+1){
    if(flag==1){break;}
    repp(j,i+1,N+1){
      if(g==0){flag=1;}
      if(flag==1){break;}
      g--;
      qu.push(P(i,j));
    }
  }
  cout<<qu.size()<<endl;
  while(!qu.empty()){
    auto t=qu.front();qu.pop();
    cout<<t.first<<' '<<t.second<<endl;
  }
}
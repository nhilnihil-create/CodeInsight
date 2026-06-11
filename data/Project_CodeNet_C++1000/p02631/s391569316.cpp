#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
typedef long long ll;
struct edge { ll s, t, x; };
typedef pair<ll, ll> P;
typedef pair<ll,P> event;
const ll MAX = 510000;
const ll MOD = 1000000007;
#define INF (ll)10000000000000000


int main() {
  ll N;
  cin>>N;
  vector<ll>A(N);
  rep(i,N){cin>>A[i];}
  ll sum=0ll;
  rep(i,N){sum=sum^A[i];}
  rep(i,N){
    ll g=sum^A[i];
    cout<<g<<' ';
  }
  
  
}



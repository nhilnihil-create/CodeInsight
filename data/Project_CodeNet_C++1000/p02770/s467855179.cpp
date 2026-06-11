#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = 1<<30;
const ll mod = 1000000007LL;

int main() {
  ll k,q;
  cin>>k>>q;
  vector<ll> d(k);
  for(ll i = 0LL; i < k; i++) cin>>d[i];
  for(ll i = 0LL; i < q; i++){
    ll n,x,m;
    cin>>n>>x>>m;
    vector<ll> S(k,0LL);
    for(ll j = 0LL; j < k; j++){
      ll t = d[j]%m;
      if(t==0LL) t+=m;
      if(j==0LL)S[j]=t;
      else S[j]=S[j-1]+t;
    }
    ll total = x%m + ((n-1LL)/k)*S[k-1];
    if((n-1LL)%k!=0LL) total += S[((n-1LL)%k)-1LL];
    ll ans = n-(total/m)-1LL;
    cout<<ans<<endl;
  }
}
/*{{{*/
#include<bits/stdc++.h>

typedef long long ll;

#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define FORR(i,a,b) for(ll i=b-1;i>=a;i--)

#define vl vector<ll>
#define pll pair<ll,ll>

#define DEBUG(x) cout<<#x<<": "<<x<<endl

using namespace std;
/*}}}*/

int main() {
  ll n;
  cin >> n;
  ll ans = n * (n+1) * (n+2) / 6;
  REP(i,n-1){
    ll u,v;
    cin >> u >> v;
    if(u>v) swap(u,v);
    ans -= u * (n-v+1);
  }
  cout << ans << endl;
  return 0;
}

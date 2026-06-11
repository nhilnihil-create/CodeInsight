#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

int main() {
  ll n;
  cin >> n;
  vec a(n);
  vec b(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  for(ll i=0;i<n;i++) cin >> b[i];
  priority_queue<pll,vector<pll>,greater<pll>> q;
  for(ll i=0;i<n;i++) {
    if(b[i]>a[i]&&b[i]>b[(i+1)%n]+b[(i+n-1)%n]) {
      q.push(pll(b[i],i));
    }
  }
  ll ans=0;
  while(q.size()) {
    ll t=q.top().second;
    q.pop();
    if(a[t]>=b[t]) continue;
    if(b[t]<=b[(t+1)%n]+b[(t+n-1)%n]) continue;
    ll count=min((b[t]-a[t])/(b[(t+1)%n]+b[(t+n-1)%n]),b[t]/(b[(t+1)%n]+b[(t+n-1)%n]));
    b[t]-=count*(b[(t+1)%n]+b[(t+n-1)%n]);
    ans+=count;
    for(ll i=-1;i<2;i++) {
      if(i==0) continue;
      ll nt=(t+i+n)%n;
      if(a[nt]>=b[nt]) continue;
      if(b[nt]<=b[(nt+1)%n]+b[(nt+n-1)%n]) continue;
      q.push(pll(b[nt],nt));
    }
  }
  for(ll i=0;i<n;i++) {
    if(a[i]!=b[i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
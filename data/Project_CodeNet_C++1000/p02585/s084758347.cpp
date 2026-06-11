#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

int main() {
  ll n,k;
  cin >> n >> k;
  vec p(n),c(n);
  for(ll i=0;i<n;i++) {
    cin >> p[i];
    p[i]--;
  }
  for(ll i=0;i<n;i++) {
    cin >> c[i];
  }
  ll ans=-inf;
  set<ll> al;
  for(ll idx=0;idx<n;idx++) {
    if(al.count(idx)) continue;
    vec a;
    for(ll i=idx;;) {
      a.push_back(c[i]);
      al.insert(i);
      i=p[i];
      if(i==idx) break;
    }
    ll N=a.size();
    vec mo(N+1,-inf);
    mo[0]=0;
    for(ll i=0;i<N;i++) {
      ll sum=0;
      for(ll j=0;j<N;j++) {
        idx=(i+j)%N;
        sum+=a[idx];
        mo[j+1]=max(mo[j+1],sum);
      }
    }
    ll sum=mo[N];
    for(ll i=1;i<N;i++) {
      mo[i+1]=max(mo[i+1],mo[i]);
    }
    
    if(k<=N) {
      ans=max(ans,mo[k]);
    }
    else {
      ans=max(ans,mo[N]);
      ans=max(ans,k/N*sum+max(mo[k%N],0LL));
      ans=max(ans,(k/N-1)*sum+max(mo[N],0LL));
    }
  }
  cout << ans << endl;
}
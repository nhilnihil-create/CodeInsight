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
  ll n;
  cin >> n;
  vec a(n);
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    a[i]--;
  }
  vec idx(n);
  for(ll i=0;i<n;i++) idx[a[i]]=i;
  ll ans=0;
  set<ll> s;
  for(ll x=n-1;x>=0;x--) {
    ll i=idx[x];
    ll c=0;
    {
      s.insert(i);
      vec l(2,-1);
      vec r(2,n);
      auto it=s.find(i);
      for(ll j=0;j<2;j++) {
        if(it==s.begin()) break;
        l[j]=*--it;
      }
      it=s.find(i);
      for(ll j=0;j<2;j++) {
        ++it;
        if(it==s.end()) break;
        r[j]=*it;
      }
      vec ls(2);
      ls[0]=i-l[0];
      ls[1]=l[0]-l[1];
      vec rs(2);
      rs[0]=r[0]-i;
      rs[1]=r[1]-r[0];
      for(ll j=0;j<2;j++) {
        c+=ls[j]*rs[1-j];
      }
    }
    ans+=(x+1)*c;
  }
  cout << ans << endl;
}
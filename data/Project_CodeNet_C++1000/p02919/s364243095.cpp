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
  vector<pll> a(n);
  for(ll i=0;i<n;i++) {
    ll v;
    cin >> v;
    a[i]={v,i};
  }
  sort(a.rbegin(),a.rend());
  set<ll> al,ar;
  al.insert(-a[0].second);
  al.insert(1);
  al.insert(-n);
  ar.insert(a[0].second);
  ar.insert(-1);
  ar.insert(n);
  ll ans=0;
  for(ll i=1;i<n;i++) {
    ll v=a[i].first;
    ll id=a[i].second;
    auto r=ar.lower_bound(id);
    auto tr=ar.upper_bound(*r);
    auto l=al.lower_bound(-id);
    auto tl=al.upper_bound(*l);
    ll dr=min(max(*tr,*r),n)-*r;
    ll dl=-*l+-max(-max(*tl,*l),-1LL);
    ans+=v*dr*(id+*l);
    ans+=v*(*r-id)*dl;
    al.insert(-id);
    ar.insert(id);
  }
  cout << ans << endl;
}
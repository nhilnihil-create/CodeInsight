#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e15;

vector<ll> divisor(ll n) {
  vector<ll> res;
  for(ll i=1;i*i<=n;i++) {
    if(n%i==0) {
      res.push_back(i);
      if(i!=n/i) {
        res.push_back(n/i);
      }
    }
  }
  return res;
}

int main() {
  ll n,k;
  cin >> n >> k;
  vec a(n);
  ll sum=0;
  for(ll i=0;i<n;i++) {
    cin >> a[i];
    sum+=a[i];
  }
  sort(a.rbegin(),a.rend());
  vec div=divisor(sum);
  ll ans=1;
  for(ll i:div) {
    if(i==1) continue;
    ll tmp=0;
    ll cnt=0;
    vec aa(n);
    for(ll j=0;j<n;j++) {
      aa[j]=a[j]%i;
      tmp+=aa[j];
    }
    sort(aa.rbegin(),aa.rend());
    for(ll j=0;j<n;j++) {
      tmp-=i;
      cnt+=(i-aa[j]);
      if(tmp<=0) break;
    }
    if(cnt<=k) {
      ans=max(ans,i);
    }
  }
  cout << ans << endl;
}
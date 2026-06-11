#include<bits/stdc++.h>
using namespace std;
#define all(a)  (a).begin(),(a).end()
typedef long long ll;
const ll mod=1000000007;
#define repi(i,a,b) for(ll i=ll(a);i<ll(b);++i)

int main() {
  ll n,k;cin>>n>>k;
  vector<ll> a(n);
  for(ll i=0;i<n;++i)cin>>a[i];
  vector<ll> pre(n,0LL),post(n,0LL);
  for(ll i=0;i<n;++i){
    ll cpre =0LL;
    ll cpost =0LL;
    for(ll j=0;j<n;++j){
      if(a[i]>a[j]){
        ++cpost;
        if(i<j)++cpre;
      }
    }
    pre[i] = cpre;
    post[i] = cpost;
  }
  ll out=0LL;
  for(int i=0;i<n;++i) out += (k*pre[i])%mod;
  out = out%mod;
  for(int i=0;i<n;++i) {
    ll ele = k*(k-1)/2LL;
    ele = ele%mod;
    out += post[i]*ele;
    out = out%mod;
  }
  cout << out << endl;
  return 0;
}

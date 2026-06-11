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
  ll n,k;
  cin >> n >> k;
  vec a(n);
  for(ll i=0;i<n;i++) cin >> a[i];
  ll ans=0;
  for(ll i=0;i<n;i++) {
    for(ll j=0;j<n;j++) {
      if(i==j) continue;
      if(i<j&&a[i]>a[j]) (ans+=k*(k+1)/2)%=mod;
      if(i>j&&a[i]>a[j]) (ans+=k*(k-1)/2)%=mod;
    }
  }
  cout << ans << endl;
}
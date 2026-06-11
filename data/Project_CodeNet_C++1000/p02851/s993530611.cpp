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
  ll big=1e9;
  ll n,k;
  cin >> n >> k;
  vec a(n+1);
  for(ll i=1;i<=n;i++) {
    cin >> a[i];
    a[i]+=a[i-1];
  }
  for(ll i=0;i<=n;i++) {
    a[i]=(a[i]-i+big*k)%k;
  }
  map<ll,ll> b;
  ll ans=0;
  for(ll i=0;i<=n;i++) {
    if(i>=k) {
      b[a[i-k]]--;
    }
    ans+=b[a[i]];
    b[a[i]]++;
  }
  cout << ans << endl;
}
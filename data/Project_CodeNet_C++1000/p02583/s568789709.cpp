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
  vec l(n);
  for(ll i=0;i<n;i++) {
    cin >> l[i];
  }
  ll ans=0;
  for(ll i=0;i<n;i++) {
    for(ll j=i+1;j<n;j++) {
      if(l[i]==l[j]) continue;
      for(ll k=j+1;k<n;k++) {
        if(l[i]==l[k]||l[j]==l[k]) continue;
        if(abs(l[i]-l[j])<l[k]&&l[k]<l[i]+l[j]) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}
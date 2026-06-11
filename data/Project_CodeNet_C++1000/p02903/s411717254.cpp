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
  ll h,w,a,b;
  cin >> h >> w >> a >> b;
  mat ans(h,vec(w));
  for(ll i=0;i<h;i++) {
    for(ll j=0;j<w;j++) {
      if((i<b&&j<a)||(i>=b&&j>=a)) {
        ans[i][j]=0;
      }
      else {
        ans[i][j]=1;
      }
    }
  }
  for(ll i=0;i<h;i++) {
    for(ll j=0;j<w;j++) {
      cout << ans[i][j];
    }
    cout << endl;
  }
}
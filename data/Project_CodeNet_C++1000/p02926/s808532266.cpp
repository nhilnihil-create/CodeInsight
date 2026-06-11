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
  vec x(n),y(n);
  for(ll i=0;i<n;i++) cin >> x[i] >> y[i];
  ll ans=0;
  for(ll i=0;i<n;i++) {
    for(ll k=0;k<n;k++) {
      ll dx=x[k]+x[i],dy=y[k]+y[i];
      if(dx*dx+dy*dy==0) continue;
      ll sx=0,sy=0;
      for(ll j=0;j<n;j++) {
        if(dx*x[j]+dy*y[j]>=0) {
          sx+=x[j];
          sy+=y[j];
        }
      }
      ans=max(ans,sx*sx+sy*sy);
    }
  }
  cout << fixed << setprecision(20) << sqrt(ans) << endl;
}
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
  ll m,d;
  cin >> m >> d;
  ll ans=0;
  for(ll i=1;i<=m;i++) {
    for(ll j=1;j<=d;j++) {
      ll d1=j/10;
      ll d2=j%10;
      if(d1<=1||d2<=1) continue;
      if(d1*d2==i) ans++;
    }
  }
  cout << ans << endl;
}
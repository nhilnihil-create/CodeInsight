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
  for(ll i=1;i<=d;i++) {
    ll d1=i/10;
    ll d2=i%10;
    if(d1<=1||d2<=1) continue;
    if(d1*d2<=m) ans++;
  }
  cout << ans << endl;
}
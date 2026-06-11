#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

vec l(1e5+5),r(1e5+5),num(1e5+5);

int main() {
  ll n;
  cin >> n;
  for(ll i=1;i<=n;i++) {
    ll tmp;
    cin >> tmp;
    num[tmp]=i;
    l[i]=i-1;
    r[i]=i+1;
  }
  ll ans=0;
  for(ll i=1;i<=n;i++) {
    ll x=l[num[i]],w=l[x];
    ll y=r[num[i]],z=r[y];
    if(x!=0) ans+=1LL*(x-w)*(y-num[i])*i;
    if(y!=n+1) ans+=1LL*(z-y)*(num[i]-x)*i;
    l[y]=x;
    r[x]=y;
  }
  cout << ans << endl;
}
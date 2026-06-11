#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=5e18;

vec l(1e5+5),r(1e5+5),w(1e5+5);

int main() {
  ll n;
  cin >> n;
  for(ll i=1;i<=n;i++) {
    ll tmp;
    cin >> tmp;
    w[tmp]=i;
    l[i]=i-1;
    r[i]=i+1;
  }
  ll ans=0;
  for(ll i=1;i<=n;i++) {
    ll b=l[w[i]],a=l[b];
    ll c=r[w[i]],d=r[c];
    if(b!=0) ans+=1LL*(b-a)*(c-w[i])*i;
    if(c!=n+1) ans+=1LL*(d-c)*(w[i]-b)*i;
    l[c]=b;
    r[b]=c;
  }
  cout << ans << endl;
}
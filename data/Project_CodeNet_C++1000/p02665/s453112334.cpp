#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<62;

int main() {
  ll n;
  cin >> n;
  vec a(n+1);
  for(ll i=0;i<=n;i++) cin >> a[i];
  vec ans(n+1);
  ans[n]=a[n];
  ll f=0;
  for(ll i=n;i;i--) {
    ll res=ans[i]+a[i-1];
    ans[i-1]=res;
  }
  ans[0]=1;
  for(ll i=0;i<n;i++) {
    ll res=(ans[i]-a[i])*2;
    ans[i+1]=min(ans[i+1],res);
  }
  ll res=0;
  for(ll i=0;i<=n;i++) {
    res+=ans[i];
    if(ans[i]<=0) f=1;
    if(i==n&&ans[i]!=a[i]) f=1;
  }
  if(f) res=-1;
  cout << res << endl;
}
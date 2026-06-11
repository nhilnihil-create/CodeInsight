#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<62;

ll fact(ll n) {
  ll res=0;
  while(n/2) {
    res+=n/2;
    n/=2;
  }
  return res;
}

ll comb(ll n, ll k) {
  ll res=fact(n)-fact(k)-fact(n-k);
  if(res) res=0;
  else res=1;
  return res;
}

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  if(n<=4) {
    mat a(n,vec(n));
    for(ll i=0;i<n;i++) {
      a[0][i]=s[i]-'0';
    }
    for(ll i=1;i<n;i++) {
      for(ll j=0;j<n-i;j++) {
        a[i][j]=abs(a[i-1][j]-a[i-1][j+1]);
      }
    }
    cout << a[n-1][0] << endl;
  }
  else {
    ll sum=0;
    ll f=1;
    for(ll i=0;i<n;i++) {
      ll idx=(s[i]-'1');
      if(idx==1) f=0;
      sum+=idx*comb(n-1,i);
      sum%=2;
    }
    if(f) {
      sum=0;
      for(ll i=0;i<n;i++) {
        ll idx=(s[i]-'1')/2;
        sum+=idx*comb(n-1,i);
        sum%=2;
      }
      sum*=2;
    }
    cout << sum << endl;
  }
}
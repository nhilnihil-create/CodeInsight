#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vec> mat;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
//const ll mod=998244353;
const ll inf=1LL<<61;

vec tfact(1e7+1);
void fact(ll n) {
  for(ll i=0;i<=n;i++) {
    ll tmp=i;
    ll cnt=0;
    while(tmp&&tmp%2==0) {
      tmp/=2;
      cnt++;
    }
    tfact[i]=cnt;
    if(i) {
      tfact[i]+=tfact[i-1];
    }
  }
}

ll comb(ll n, ll k) {
  return (tfact.at(n)-tfact.at(k)-tfact.at(n-k))==0;
}

int main() {
  ll n;
  cin >> n;
  string s;
  cin >> s;
  fact(n);
  vec a(n);
  for(ll i=0;i<n;i++) {
    a[i]=s[i]-'0';
  }
  ll f=0;
  for(ll i=0;i<n;i++) {
    if(a[i]==2) f=1;
  }
  if(f) {
    for(ll i=0;i<n;i++) {
      a[i]%=2;
    }
    ll ans=0;
    for(ll i=0;i<n;i++) {
      ans+=comb(n-1,i)*a[i];
      ans%=2;
    }
    cout << ans << endl;
  }
  else {
    for(ll i=0;i<n;i++) {
      if(a[i]==3) a[i]=2;
    }
    ll ans=0;
    for(ll i=0;i<n;i++) {
      ans+=comb(n-1,i)*a[i];
      ans%=2;
    }
    if(ans) ans++;
    cout << ans << endl;
  }
}
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
  string s;
  cin >> s;
  ll n=s.size();
  ll ans=1;
  ll size=1;
  for(ll i=1;i<n;i++) {
    if(size==1) {
      if(s[i]==s[i-1]) {
        if(i==n-1) {
          break;
        }
        size=2;
        i++;
        ans++;
      }
      else {
        ans++;
      }
    }
    else {
      ans++;
      size=1;
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll n;
  cin >> n;
  vector<string>s(n);
  vector<ll>t(n);
  for(ll i=0;i<n;i++){
    cin >> s[i] >> t[i];
  }
  ll ans=0;
  string x;
  cin >> x;
  ll ti;
  for(ll i=0;i<n;i++){
    if(s[i]==x){
      ti=i;
      break;
    }
  }
  for(ll i=ti+1;i<n;i++){
    ans+=t[i];
  }
  cout << ans << endl;
}
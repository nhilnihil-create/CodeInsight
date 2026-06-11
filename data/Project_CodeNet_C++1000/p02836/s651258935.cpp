#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  string s;
  cin >> s;
  ll n=s.size();
  ll ans=0;
  for(ll i=0;i<n/2;i++){
    if(s[i]!=s[n-i-1]) ans++;
  }
  cout << ans << endl;
}
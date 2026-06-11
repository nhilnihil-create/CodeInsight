#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll n;
  cin >> n;
  vector<char>s(n);
  for(ll i=0;i<n;i++){
    cin >> s[i];
  }
  ll ans=0;
  for(ll i=0;i<n-2;i++){
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
      ans++;
    }
  }
  cout << ans << endl;
}
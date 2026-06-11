#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
  ll n;
  cin >> n;
  string s,h;
  cin >> s >> h;
  string ans;
  for(ll i=0;i<n;i++){
    ans.push_back(s[i]);
    ans.push_back(h[i]);
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int n;
  cin >> n;
  string s[n];
  map<string,ll> mp;
  rep(i,n) {
    cin >> s[i];
    sort(s[i].begin(),s[i].end());
    mp[s[i]]++;
  }
  ll ans = 0;
  for(auto x : mp) ans += x.second * (x.second - 1) / 2;
  cout << ans << endl;
  return 0;
}

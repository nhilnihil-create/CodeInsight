#include <bits/stdc++.h>
using namespace std;

using LL = long long int;

int main() {

  int n;
  cin >> n;
  map<string, LL> mp;

  for(int i = 0; i < n; ++i){
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    mp[s]++;
  }

  LL ans = 0;

  for(auto p : mp) ans += p.second*(p.second-1)/2;

  cout << ans << endl;

  return 0;
}

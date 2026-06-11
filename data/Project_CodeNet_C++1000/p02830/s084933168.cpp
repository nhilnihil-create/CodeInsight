#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  string s,t;
  cin >> s >> t;
  string ans;
  for (int i = 0; i < n; ++i) {
    ans += s[i];
    ans += t[i];
  }
  cout << ans << endl;
}

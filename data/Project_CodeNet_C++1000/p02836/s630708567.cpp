#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  string s;
  cin >> s;
  int n = s.length();
  int ans = 0;
  for (int i = 0; i < n/2; ++i) {
    if (s[i] != s[n-1-i]) {
      ++ans;
    }
  }
  cout << ans << endl;

}

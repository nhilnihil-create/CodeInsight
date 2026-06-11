#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;
  string s;
  cin >> s;
  int i = -1;
  int ans = 0;
  while (i < n) {
    i = s.find("ABC", i+1);
    if (i == string::npos) break;
    ++ans;
  }
  cout << ans << endl;
}

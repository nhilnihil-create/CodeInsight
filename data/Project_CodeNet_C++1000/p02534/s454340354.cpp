#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll K;
  cin >> K;
  string ans;
  string s = "ACL";
  for (int i = 0; i < K; ++i) ans += s;
  cout << ans << endl;

}

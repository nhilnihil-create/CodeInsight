#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
#define endl '\n'

ll cnt[10][10];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  ll n;
  cin >> n;

  ll ans = 0;
  for (ll i = 1; i <= n; ++i) {
    string s = to_string(i);
    ++cnt[s[0]-'0'][s.back()-'0'];
  }
  for (ll i = 1; i <= n; ++i) {
    string s = to_string(i);
    ans += cnt[s.back()-'0'][s[0]-'0'];
  }
  cout << ans << endl;

}

//author: Harsh :)
#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
#define F first
#define S second
const ll mod = 1e9 + 7;
const ll INF = 922337203685477;
#define pb push_back
#define deb(x) cout << '>' << #x << ':' << x << endl;
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
#define maxN 100007
using namespace std;
int main() {
  fastio;
  string s;
  cin >> s;
  ll n = s.length();
  ll c = 0;
  vector<ll>ans(n, 0);
  for (ll i = 0; i < 2; ++i) {
    for (ll j = 0; j < n; ++j) {
      if (s[j] == 'R') ++c;
      else {
        ans[j] += (c / 2);
        ans[j - 1] += (c + 1) / 2;
        c = 0;
      }
    }
    reverse(ans.begin(), ans.end());
    reverse(s.begin(), s.end());
    for (ll i = 0; i < n; ++i) {
      if (s[i] != 'R') s[i] = 'R';
      else s[i] = 'L';
    }
  }
  for (auto i : ans) cout << i << " ";
}

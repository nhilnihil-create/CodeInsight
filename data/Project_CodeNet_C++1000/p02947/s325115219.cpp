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
  ll n = 0;
  cin >> n;
  map<string, ll>mp;
  ll ans = 0;
  for (ll i = 0; i < n; ++i) {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    ++mp[s];
  }
  for (auto i : mp) {
    ll x = i.S;
    ans += x * (x - 1) / 2;
  }
  cout << ans;
}

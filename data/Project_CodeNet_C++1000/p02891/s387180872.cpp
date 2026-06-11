#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
ll inf = LLONG_MAX;
long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = s.size();

  vll a(0);
  for (ll i = 0; i < n; i++) {
    char c = s[i];
    ll cnt = 0;
    while (c == s[i] && i < n) {
      i++;
      cnt++;
    }
    a.push_back(cnt);
    i--;
  }

  ll ans = 0;
  for (ll i = 0; i < a.size(); i++) {
    ans += a[i] / 2;
  }
  if (s[0] != s[n - 1]) cout << ans * k << endl;
  else {
    if (a.size() == 1) {
      cout << a[0] * k / 2 << endl;
      return 0;
    }
    a[0] += a.back();
    a.pop_back();
    ll m = 0;
    for (ll i = 0; i < a.size(); i++) {
      m += a[i] / 2;
    }
    cout << ans + m * (k - 1) << endl;
  }
}
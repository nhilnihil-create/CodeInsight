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
  ll n, a, b, c, d;
  string s;
  cin >> n >> a >> b >> c >> d >> s;
  a--;
  b--;
  c--;
  d--;

  for (ll i = a; i < c; i++) {
    if (s[i] == '#' && s[i + 1] == '#') {
      No();
      return 0;
    }
  }
  for (ll i = b; i < d; i++) {
    if (s[i] == '#' && s[i + 1] == '#') {
      No();
      return 0;
    }
  }

  if (a < b &&  b < d && d < c) {
    for (ll i = b; i <= d; i++) {
      if (s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.') {
        Yes();
        return 0;
      }
    }
    No();
  }
  else Yes();
}
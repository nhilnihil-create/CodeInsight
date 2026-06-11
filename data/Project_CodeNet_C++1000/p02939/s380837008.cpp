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
  cin >> s;
  ll n = s.size();

  ll ans = 1;
  string t = s.substr(0, 1), reset;
  for (ll i = 1; i < n; i++) {
    string u = s.substr(i, 1);
    if (u == t && i + 1 < n) {
      u.push_back(s[i + 1]);
      i++;
    }
    if (u == t) break;
    t = u;
    u = reset;
    ans++;
  }
  cout << ans << endl;
}
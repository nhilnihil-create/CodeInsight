#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define all(x) (x).begin(), (x).end()
#define endl '\n'
#define fsp(x) cout << fixed << setprecision(x)
const ll inf = LLONG_MAX;
const long double pi = M_PI;
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}

int main() {
  ll m, d;
  cin >> m >> d;
  ll ans = 0;
  for (ll i = 1; i <= m; i++) {
    for (ll j = 1; j <= d; j++) {
      ll d10 = j / 10, d1 = j % 10;
      if (d10 >= 2 && d1 >= 2 && d10 * d1 == i) {
        ans++;
        //cout << i << " " << j << endl;
      }
    }
  }
  cout << ans << endl;
}
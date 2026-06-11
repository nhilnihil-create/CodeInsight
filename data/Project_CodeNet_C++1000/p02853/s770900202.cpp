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
  ll x, y;
  cin >> x >> y;
  ll ans = max(400000 - x * 100000, 0ll) + max(0ll, 400000 - y * 100000);
  if (x == 1 && y == 1) ans += 400000;
  cout << ans << endl;
}
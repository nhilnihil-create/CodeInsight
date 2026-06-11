#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
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
  ll s;
  cin >> s;
  ll a, b, c, d, e, f;
  a = 0;
  b = 0;
  c = 1e9;
  d = 1;
  e = s % c * (-1) + 1e9;
  f = s / c + 1;
  if (s == 1e18) {
    f--;
    e = 0;
  }
  cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << endl;
}
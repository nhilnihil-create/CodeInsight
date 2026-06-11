#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (ll i = j; i <= n; i++)
#define per(i, j, n) for (ll i = j; i >= n; i--)
#define ll long long
#define ld long double
#define ld long double
#define ii pair<ll, ll>
#define vii vector<ii>
#define vi vector<ll>
#define adj unordered_map<ll, vii>
#define MOD 1000000007
#define PI 3.14159265359
#define db1(x) cout << #x " = " << x << endl;

void i1d(vi &v) {
  for (auto &i : v)
    cin >> i;
}

void p1d(vi &v) {
  for (auto i : v)
    cout << i << ' ';
  cout << endl;
}

vi x(5);

void solve() {
  // Code goes here
  i1d(x);
  rep(i, 0, 4) {
    if (x[i] == 0) {
      cout << i + 1 << '\n';
      break;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  solve();
}
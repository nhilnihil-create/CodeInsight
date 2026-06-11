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

//二進数展開
vll into_binary(ll a) {
  vll v(60, 0);
  ll b = pow(2, 59);
  for (ll i = 0; i < 60; i++) {
    if (a >= b) {
      v[i]++;
      a -= b;
      if (a == 0) break;
    }
    b /= 2;
  }
  return v;
}

int main() {
  ll n;
  cin >> n;

  vll a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  vector<vll> b(n);
  for (ll i = 0; i < n; i++) {
    b[i] = into_binary(a[i]);
  }

  vll v = b[0];
  for (ll i = 1; i < n; i++) {
    for (ll j = 0; j < 60; j++) {
      if (v[j] == b[i][j]) v[j] = 0;
      else v[j] = 1;
    }
  }

  for (ll i = 0; i < 60; i++) {
    if (v[i] == 1) {
      No();
      return 0;
    }
  }
  Yes();
}
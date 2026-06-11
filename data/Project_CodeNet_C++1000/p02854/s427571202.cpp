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
  ll n;
  cin >> n;
  vll a(n);
  deque<ll> dq;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    dq.push_back(a[i]);
  }
  ll l = 0, r = 0;
  while (!dq.empty()) {
    if (l <= r) {
      l += dq.front();
      dq.pop_front();
    }
    else {
      r += dq.back();
      dq.pop_back();
    }
  }
  cout << abs(l - r) << endl;
}
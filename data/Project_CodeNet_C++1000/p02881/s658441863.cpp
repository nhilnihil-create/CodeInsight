#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(x) (x).begin, (x).end
#define sz(x) (int)(x).size()
#define rep1(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define get4(_1, _2, _3, _4, ...) _4
#define rep(...) get4(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> cand;
  for (ll i = 1; i * i <= n; i++) {
    if (i * (n / i) == n) cand.pb({i, n / i});
  }
  for (int i = sz(cand) - 1; ~i; i--) {
    cout << cand[i].first + cand[i].second - 2 << '\n';
    break;
  }
  return 0;
}

#line 1 "/mnt/c/Users/leafc/dev/compro/lib/template.hpp"

#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>

using namespace std;

#line 2 "tmp.cpp"

bool f(ll x, const ll k, const vl &a) {
  int n = a.size();
  vl b(n);
  REP(i, n) { b[i] = a[i] % x; }
  sort(ALL(b));
  vl cum1(n), cum2(n);
  cum1[0] = b[0];
  FOR(i, 1, n) { cum1[i] = cum1[i - 1] + b[i]; }

  cum2[n - 1] = (x - b[n - 1]) % x;
  for (int i = n - 2; i >= 0; i--) {
    cum2[i] = cum2[i + 1] + (x - b[i]) % x;
  }

  REP(i, n - 1) {
    if (abs(cum1[i] - cum2[i + 1]) % x == 0 && max(cum1[i], cum2[i + 1]) <= k) {
      return true;
    }
  }

  bool equ = true;
  REP(i, n) { equ = equ && b[i] == 0; }
  return equ;
}

int main() {
  ll n, k;
  cin >> n >> k;
  ll sum = 0;
  vl a(n);
  REP(i, n) {
    cin >> a[i];
    sum += a[i];
  }
  ll ans = 0;
  vl candidate;
  FOR(i, 1, sqrt(sum) + 1) {
    if (sum % i == 0) {
      candidate.push_back(i);
      candidate.push_back(sum / i);
    }
  }
  for (const auto c : candidate) {
    if (f(c, k, a)) {
      ans = max(c, ans);
    }
  }
  cout << ans << endl;
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pull = pair<ull, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

bool check(ll t, ll k, vector<ll>&a, vector<ll>&f, vector<ll>&pr) {
  //cout << t << endl;
  for (int i = 0; i < 1000001; i++) pr[i] = 0;
  for (int i = 0; i < f.size(); i++) {
    ll index = min(t/f[i], 1000000LL);
    pr[index]++;
  }
  for (int i = 1; i < 1000001; i++) pr[i] += pr[i-1];
  ll cnt = 0;
  for (int i = 0; i < 1000001; i++) cnt += max(0LL, pr[i] - a[i]);
  //cout << "fin" << endl;
  if (cnt <= k) return true;
  else return false;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;
  vector<ll> a(1000001), f(n);
  for (int i = 0; i < n; i++) {
    ll p;
    cin >> p;
    a[p]++;
  }
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  for (int i = 1; i < 1000001; i++) a[i] += a[i-1];

  vector<ll>pr(1000001);

  ll ok = 1000000000000000001LL, ng = -1, mid;
  while (abs(ok - ng) > 1) {
    mid = (ok + ng) / 2;
    if (check(mid, k, a, f, pr)) ok = mid;
    else ng = mid;
  }
  cout << ok << endl;
}

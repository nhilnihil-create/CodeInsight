#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector<ll> makeDivisors(ll n) {
  vector<ll> ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n%i == 0) {
      ret.push_back(i);
      if(i*i != n) ret.push_back(n/i);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

bool check(ll n, ll k) {
  while (n >= k) {
    if (n%k == 0) n /= k;
    else n %= k;
  }
  return n == 1;
}

int main() {
  // N%Kは0か1
  ll N;
  cin >> N;
  vector<ll> cand = makeDivisors(N);
  vector<ll> cand2 = makeDivisors(N-1);
  for (ll x : cand2) {
    cand.push_back(x);
  }
  int ans = 0;
  for (ll x : cand) {
    if (x >= 2 && check(N, x)) ans++;
  }
  cout << ans << '\n';
  return 0;
}
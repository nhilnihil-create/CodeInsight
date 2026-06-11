#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

const ll INF = 1e12;
vector<ll> A;
vector<ll> F;
ll N, K;

bool check(ll x) {
  // K回以下の修行でx以下の成績に出来るならtrueを返す
  ll cnt = 0;
  rep(i, N) {
    ll need = x / F[i];
    ll y = A[i] - need;
    cnt += ((y < 0) ? 0 : y);
  }
  return (cnt <= K);
}

int main() {
  // sort、二分探索
  cin >> N >> K;
  A.resize(N);
  F.resize(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());

  ll ok = INF; ll ng = -1;
  while (abs(ng-ok) > 1) {
    ll mid = (ok+ng) / 2;
    if (check(mid)) ok = mid;
    else ng = mid;
  }
  cout << ok << '\n';
  return 0;
}
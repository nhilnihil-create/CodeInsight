#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------

ll N, K;
ll A[201010], F[201010];

bool can(ll x) {
  ll cnt = 0;
  rep(i, 0, N) {
    ll limit = x / F[i];
    cnt += max(0LL, A[i] - limit);
  }
  return cnt <= K;
}

int main() {
  cin >> N >> K;
  rep(i, 0, N) { cin >> A[i]; }
  rep(i, 0, N) { cin >> F[i]; }
  sort(A, A + N);
  sort(F, F + N, greater<ll>());

  ll ub = 1e+13;
  ll lb = -1;
  while (ub - lb > 1) {
    ll mid = (ub + lb) / 2;
    if (can(mid)) {
      ub = mid;
    } else {
      lb = mid;
    }
  }
  cout << ub;
}

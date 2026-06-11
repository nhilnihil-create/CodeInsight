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

ll N;
ll A[1010][1010];
ll cnt[1010];
bool done[1010];

int main() {
  cin >> N;
  repe(i, 1, N) {
    rep(j, 0, N - 1) { cin >> A[i][j]; }
    A[i][N - 1] = INF;
  }

  ll ans = 0;
  vector<ll> updated;
  repe(i, 1, N) { updated.push_back(i); }
  while (true) {
    repe(i, 1, N) { done[i] = false; }
    bool ok = false;
    vector<ll> updated_next;
    for (auto i : updated) {
      if (done[i]) continue;

      ll op = A[i][cnt[i]];
      if (op == INF) continue;
      if (done[op]) continue;

      if (A[op][cnt[op]] == i) {
        done[i] = true;
        done[op] = true;
        ++cnt[i];
        ++cnt[op];
        ok = true;
        updated_next.push_back(i);
        updated_next.push_back(op);
      }
    }
    if (!ok) {
      repe(i, 1, N) {
        if (cnt[i] != N - 1) {
          cout << -1;
          return 0;
        }
      }
      cout << ans;
      return 0;
    }
    updated = updated_next;
    ++ans;
  }
}

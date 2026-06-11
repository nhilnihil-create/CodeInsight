#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
// const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
int N, P;
string S;
map<ll, ll> rem;

int MOD = 1000000007;

ll ppow(ll a, ll b) {
  a %= MOD;
  ll res = 1;
  while (b) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}

int main() {
  cin >> N >> P;
  cin >> S;
  MOD = P;

  if (P == 2) {
    ll ans = 0;
    for (int i = S.size() - 1; i >= 0; --i) {
      int num = S[i] - '0';
      if (num % 2 == 0) {
        ans += i + 1;
      }
    }
    cout << ans << endl;
    return 0;
  }

  if (P == 5) {
    ll ans = 0;
    for (int i = S.size() - 1; i >= 0; --i) {
      int num = S[i] - '0';
      if (num % 5 == 0) {
        ans += i + 1;
      }
    }
    cout << ans << endl;
    return 0;
  }

  ll cur = 0;
  for (int i = 1; i <= S.size(); ++i) {
    int num = S[S.size() - i] - '0';
    cur += num * ppow(10, i - 1);
    cur %= P;
    ++rem[cur];
  }
  ++rem[0];

  ll ans = 0;
  for (auto e : rem) {
    ll v = e.second;
    ans += v * (v - 1) / 2;
  }
  cout << ans << endl;
}

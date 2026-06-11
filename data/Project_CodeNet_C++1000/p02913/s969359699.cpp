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

int N;
string S;
using ull = unsigned long long;
ull csum[5010];
ull pow3[5010];

bool can(int i, int j, int x) {
  if (j + x >= S.size()) {
    return false;
  }

  if (i + x >= j) {
    return false;
  }

  ull h1 = csum[i + x + 1] - csum[i];
  ull h2 = csum[j + x + 1] - csum[j];
  return h1 * pow3[j - i] == h2;
}

bool can2(int x) {
  map<ull, vector<int>> mp;
  for (int i = 0; i < S.size() - x; ++i) {
    ull h = csum[i + x + 1] - csum[i];
    h *= pow3[S.size() - i];
    if (mp[h].size() == 0) {
      mp[h].push_back(i + x);
    } else if (mp[h].back() < i) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> N;
  cin >> S;

  pow3[0] = 1;
  rep(i, 1, 5010) { pow3[i] = pow3[i - 1] * MOD; }

  rep(i, 0, N) { csum[i + 1] = csum[i] + S[i] * pow3[i]; }

  int ans = 0;
  int low = 0;
  int high = S.size();
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (can2(mid)) {
      low = mid;
      chmax(ans, low + 1);
    } else {
      high = mid;
    }
  }

  cout << ans;
}

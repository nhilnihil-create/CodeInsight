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

int N, M;
string S;
int dist[101010];

int main() {
  cin >> N >> M;
  cin >> S;

  int cnt = 0;
  int max1 = 0;
  for (auto c : S) {
    if (c == '1') {
      ++cnt;
      chmax(max1, cnt);
    } else {
      cnt = 0;
    }
  }

  if (max1 >= M) {
    cout << -1;
    return 0;
  }

  rep(i, 0, 101010) { dist[i] = inf; }
  dist[0] = 0;

  vector<int> ansrev;
  int cur = N;
  while (cur != 0) {
    for (int i = M; i >= 1; --i) {
      if (cur - i < 0) i = cur;

      if (S[cur - i] == '0') {
        cur -= i;
        ansrev.push_back(i);
        break;
      }
    }
  }

  reverse(ansrev.begin(), ansrev.end());

  for (auto e : ansrev) {
    cout << e << " ";
  }
}

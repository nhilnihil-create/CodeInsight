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
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const double pi = 3.141592653589793;
// -------------------------------------------------------

ll N, K;
ll A[201010];
ll ev[201010];

int main() {
  cin >> N >> K;
  repe(i, 1, N) { cin >> A[i]; }

  rep(i, 0, K) {
    repe(i, 0, N + 1) { ev[i] = 0; }
    repe(i, 1, N) {
      ev[max(0LL, i - A[i])]++;
      ev[min(N + 1, i + A[i] + 1)]--;
    }
    A[0] = ev[0];
    repe(i, 1, N) { A[i] = A[i - 1] + ev[i]; }

    bool br = true;
    repe(i, 2, N) {
      if (A[i] != N) {
        br = false;
      }
    }
    if (br) {
      break;
    }
  }

  repe(i, 1, N) {
    cout << A[i];
    if (i != N) {
      cout << " ";
    }
  }
}

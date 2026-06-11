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

// -------------------------------------------------------
int N;
int A[1000], B[1000];
int K;
vector<int> divs;
int sum;
int csum[1000];

int main() {
  cin >> N >> K;
  rep(i, 0, N) {
    cin >> A[i];
    sum += A[i];
  }

  for (int i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      divs.push_back(i);
      if (sum / i != i) {
        divs.push_back(sum / i);
      }
    }
  }
  sort(divs.begin(), divs.end(), greater<int>());

  for (auto d : divs) {
    rep(i, 0, N) { B[i] = A[i] % d; }
    sort(B, B + N);
    rep(i, 0, N) { csum[i + 1] = csum[i] + B[i]; }
    repe(i, 0, N) {
      ll dec = csum[i];
      ll inc = d * 1LL * (N - i) - (csum[N] - csum[i]);
      if (max(dec, inc) <= K && abs(dec - inc) % d == 0) {
        cout << d << endl;
        return 0;
      }
    }
  }
}

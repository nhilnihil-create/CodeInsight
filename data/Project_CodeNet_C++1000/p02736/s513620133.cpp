#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

int factPow2(int N) {
  int r = 0;
  while (N > 0) {
    N /= 2;
    r += N;
  }
  return r;
}

int binomMod2(int N, int K) {
  return factPow2(N) == factPow2(K) + factPow2(N - K) ? 1 : 0;
}

int main() {
  std::ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<int> A(N);
  for (int i = 0; i < N; ++i) {
    A[i] = (S[i] - '0') - 1;
  }

  vector<int> c(N);
  for (int i = 0; i < N; ++i) {
    c[i] = binomMod2(N - 1, i);
  }

  int cnt1s = 0, sum1s = 0, sum2s = 0;
  for (int i = 0; i < N; ++i) {
    if (A[i] == 1) {
      cnt1s++;
      sum1s ^= c[i];
    }
    if (A[i] == 2) {
      sum2s ^= c[i];
    }
  }
  if (cnt1s > 0) {
    cout << (sum1s ? "1" : "0") << "\n";
    return 0;
  }

  cout << (sum2s ? "2" : "0") << "\n";
  return 0;
}

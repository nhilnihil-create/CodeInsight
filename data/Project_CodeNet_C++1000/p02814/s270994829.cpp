#include <bits/stdc++.h>

using namespace std;

template <typename T>
T gcd(T a, T b) {
  return (b ? gcd(b, a % b) : a);
}

template <typename T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

int calc(int64_t x) {
  int k = 0;
  while (x % 2 == 0) {
    x /= 2;
    k++;
  }
  return k;
}

int main() {
  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  vector<int64_t> B(N);
  for (int i = 0; i < N; i++) {
    B[i] = A[i] / 2;
  }

  int64_t L = 1;
  for (int64_t b : B) {
    L = lcm(L, b);
    if (L >= M * 2) {
      cout << 0 << endl;
      return 0;
    }
  }

  unordered_set<int> S;
  for (int64_t b : B) {
    S.insert(calc(b));
  }
  if (S.size() != 1) {
    cout << 0 << endl;
    return 0;
  }

  int64_t result = M / L - M / (L * 2);
  cout << result << endl;

  return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

template <class T>
T gcd(T a, T b) {
  if (a && b) {
    return gcd(min(a, b), max(a, b) % min(a, b));
  } else {
    return a;
  }
}

template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}

int main() {
  int N;
  ll M;
  cin >> N >> M;
  ll LCM = 1;
  vector<ll> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < N; i++) {
    LCM = lcm(LCM, a[i] / 2);
    if (LCM > M) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    if ((LCM * 2 / a[i]) % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  M /= LCM;
  cout << (M + 1) / 2 << endl;
}

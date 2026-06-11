#include <iostream>
#include <cmath>

using namespace std;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(int argc, char* argv[]) {
  long long N, K;
  cin >> N >> K;

  long long a[N];
  for (int i = 0; i < N; ++i)
    cin >> a[i];

  long long inv = modinv(2, 1000000007);

  long long ret = 0;
  for (int i = 0; i < N; ++i) {
    long long after = 0;
    long long total = 0;
    for (int j = 0; j < N; ++j) {
      if (j > i && a[i] > a[j])
        ++after;
      if (a[i] > a[j])
        ++total;
    }
    ret += after * K;
    long long tmp = K;
    tmp *= ((2 * total * (K - 1) - (K - 1) * total)) % 1000000007;
    tmp %= 1000000007;
    tmp *= inv;
    tmp %= 1000000007;
    ret += tmp;
    ret %= 1000000007;
  }

  cout << ret << endl;

  return 0;
}
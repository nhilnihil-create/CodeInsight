#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 1000005
using namespace std;
using ll = long long;

int p[N];
void sieve(int n) {
  p[1] = 1;
  p[0] = 1;
  for (ll i = 2; i <= n; ++i) {
    if (p[i] == 0) {
      p[i] = i;
      for (ll j = i * i; j <= n; j += i) {
        p[j] = i;
      }
    }
  }
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &ai: a) cin >> ai;
  int max_a = *max_element(a.begin(), a.end());
  sieve(max_a);
  vector<int> cnt(max_a + 1, 0);
  for (auto ai: a) {
    while (ai > 1) {
      int prime = p[ai];
      while (ai % prime == 0) ai /= prime;
      ++cnt[prime];
    }
  }

  bool pairwise = true;
  for (int i = 0; i <= max_a; ++i) {
    if (cnt[i] > 1) {
      pairwise = false;
      break;
    }
  }
  if (pairwise) {
    cout << "pairwise coprime\n";
    return 0;
  }
  int setgcd = gcd(a[0], a[1]);
  for (int i = 2; i < n; ++i) {
    setgcd = gcd(setgcd, a[i]);
  }
  if (setgcd == 1) {
    cout << "setwise coprime\n";
  } else {
    cout << "not coprime\n";
  }

  return 0;
}

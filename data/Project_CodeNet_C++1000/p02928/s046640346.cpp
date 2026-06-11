#include <bits/stdc++.h>
using namespace std;

int main() {
  uint64_t N, K;
  cin >> N >> K;
  vector<uint64_t> v(N);
  for (uint64_t i = 0LL; i < N; i++) {
    uint64_t x;
    cin >> x;
    v.at(i) = x;
  }
  vector<uint64_t> va(N), vb(N);
  for (uint64_t i = 0LL; i< N; i++) {
    uint64_t cnt = 0LL;
    for (uint64_t j = 0; j < N; j++) {
      if (v.at(i) > v.at(j)) cnt++;
    }
    va.at(i) = cnt;
  }
  for (uint64_t i = 0LL; i < N; i++) {
    uint64_t cnt = 0LL;
    for (uint64_t j = i; j < N; j++) {
      if (v.at(i) > v.at(j)) cnt++;
    }
    vb.at(i) = cnt;
  }
  uint64_t a = 0LL, b = 0LL;
  for (uint64_t i = 0LL; i < N; i++) {
    a += va.at(i);
    b += vb.at(i);
  }
    uint64_t c = ((a * (((K * (K-1)) / 2)% 1000000007)) % 1000000007LL + (b * K) % 1000000007LL ) % 1000000007LL;
    cout << c << endl;
}
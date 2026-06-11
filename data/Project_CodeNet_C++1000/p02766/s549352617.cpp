#include <bits/stdc++.h>
using namespace std;

template<typename T>
vector<T> convert_base(T x, T b) {
  vector<T> ret;
  T t = 1, k = abs(b);
  while (x) {
    ret.emplace_back((x * t) % k);
    if (ret.back() < 0) ret.back() += k;
    x -= ret.back() * t;
    x /= k;
    t *= b / k;
  }
  if (ret.empty()) ret.emplace_back(0);
  reverse(begin(ret), end(ret));
  return ret;
}

int main() {
  int N, K;
  cin >> N >> K;
  auto ret = convert_base(N, K);
  cout << ret.size() << "\n";
}
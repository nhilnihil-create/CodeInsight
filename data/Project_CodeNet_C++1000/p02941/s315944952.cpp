#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <numeric>
#include <set>
#include <vector>

#define TRACE(x) std::cout << #x << " = " << x << "\n"
#define _ << " _ " <<

using namespace std;

using i64 = int64_t;

int main() {
  ios_base::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<i64> A, B;
  copy_n(istream_iterator<i64>(cin), N, back_inserter(A));
  copy_n(istream_iterator<i64>(cin), N, back_inserter(B));

  i64 sumA = accumulate(begin(A), end(A), 0LL);
  i64 sumB = accumulate(begin(B), end(B), 0LL);

  set<pair<i64, int>> S;
  for (auto i = 0u; i < B.size(); ++i) {
    S.emplace(B[i], i);
  }

  auto ret = [&]() -> i64 {
    i64 ret = 0;
    while (sumB > sumA) {
      const auto it_max = --S.end();
      auto i = it_max->second;
      S.erase(it_max);

      if (A[i] == B[i]) continue;

      i64 l = B[(i - 1 + N) % N];
      i64 r = B[(i + 1) % N];

      if (B[i] <= max(l, r)) return -1;

      i64 k = min((B[i] - max(l, r) + l + r - 1) / (l + r),
                  (B[i] - A[i]) / (l + r));
      if (k <= 0) return -1;

      ret += k;

      sumB -= k * (l + r);
      B[i] -= k * (l + r);

      if (B[i] <= 0) return -1;
      S.emplace(B[i], i);
    }

    return std::equal(A.begin(), A.end(), B.begin()) ? ret : -1;
  }();

  cout << ret << '\n';
  return 0;
}

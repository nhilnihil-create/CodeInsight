#include <bits/stdc++.h>
using namespace std;

using I = long long;
using U = unsigned long long;

using F = long double;

template <typename T> using Vec = vector<T>;
template <typename K, typename V> using HashMap = unordered_map<K, V>;
template <typename T> using HashSet = unordered_set<T>;
template <typename T> using PQueue = priority_queue<T>;
template <typename T> using Uq = unique_ptr<T>;

using StrView = string_view;

auto solve(I const S, I const W) -> void {
  if (S <= W) {
    puts("unsafe");
  } else {
    puts("safe");
  }
}

auto main() -> int {
  I S;
  scanf("%lld", &S);
  I W;
  scanf("%lld", &W);
  solve(S, W);
  return 0;
}

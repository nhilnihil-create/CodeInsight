#include <bits/stdc++.h>
#define loop(n) for (int ngtkana_is_genius = 0; ngtkana_is_genius < int(n); ngtkana_is_genius++)
#define rep(i, begin, end) for(int i = int(begin); i < int(end); i++)
#define all(v) v.begin(), v.end()
#define lint long long
auto cmn = [](auto& a, auto b){if (a > b) {a = b; return true;} return false;};
auto cmx = [](auto& a, auto b){if (a < b) {a = b; return true;} return false;};
void debug_impl() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void debug_impl(Head head, Tail... tail){
  std::cerr << " " << head;
  debug_impl(tail...);
}
#define debug(...)\
  std::cerr << std::boolalpha << "[" << #__VA_ARGS__ << "]:";\
  debug_impl(__VA_ARGS__);\
  std::cerr << std::noboolalpha;

template <typename T>
std::istream& operator>> (std::istream& is, std::vector<T>& v) {
  for (auto & x : v) is >> x;
  return is;
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const std::vector<T>& v) {
  auto n = v.size();
  os << "{";
  for (size_t i = 0; i < n; i++)
    {os << (i > 0 ? "," : "") << v.at(i);}
  return os << "}";
}

// b = a * p
template < typename Value >
auto right_norm(std::vector< Value > const& a, int h) {
  int  w = a.size();
  auto b = a;
  std::vector< int > frozen(w, false);
  for (auto i = h - 1; i >= 0; i--) {
    auto pivot = -1;
    for (auto j = 0; j < w; j++) {
      if (!frozen.at(j) && (b.at(j) & (1LL << i)))
        { pivot = j; break; }
    }
    if (pivot == -1) continue;
    frozen.at(pivot) = true;
    for (auto j = 0; j < w; j++) {
      if (j != pivot && (b.at(j) & (1LL << i)))
        { b.at(j) ^= b.at(pivot); }
    }
  }
  return b;
}

int main() {
  std::cin.tie(0); std::cin.sync_with_stdio(false);
  int n; std::cin >> n;
  std::vector< lint > a(n);
  std::cin >> a;
  auto pmax = 60;
  std::vector< int > is_even(pmax, false);
  rep(i, 0, pmax) {
    auto cnt = 0;
    for (auto x : a)
      { cnt += (x >> i) & 1; }
    is_even.at(i) = (cnt % 2 == 0);
  }
  std::vector< lint > b(n);
  rep(i, 0, n) {
    auto x = a.at(i);
    auto y = 0LL;
    for (auto i = 0; i < pmax; i++) {
      if (is_even.at(i))
        { y += x & (1LL << i); }
    }
    b.at(i) = y;
  }
  b = right_norm(b, pmax);
  auto x = std::accumulate(all(b), 0LL, [](auto acc, auto x){ return acc ^ x; });
  auto y = std::accumulate(all(a), 0LL, [](auto acc, auto x){ return acc ^ x; });
  auto ret = x * 2 + y;
  std::cout << ret << std::endl;
  return 0;
}

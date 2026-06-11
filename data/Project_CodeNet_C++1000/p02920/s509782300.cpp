#include "bits/stdc++.h"
#include <iterator>

#define REP(i, n) for (ll i = 0; i < ll(n); ++i)
#define RREP(i, n) for (ll i = ll(n) - 1; i >= 0; --i)
#define FOR(i, m, n) for (ll i = m; i < ll(n); ++i)
#define RFOR(i, m, n) for (ll i = ll(n) - 1; i >= ll(m); --i)
#define ALL(v) (v).begin(), (v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end());
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

constexpr int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
constexpr int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

template <class T> bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T> bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

#include "bits/stdc++.h"

template <typename Kty> struct _const_iterator {
private:
  using _map = std::map<Kty, size_t>;
  using _iterator = typename _map::const_iterator;
  _iterator _it;
  size_t cnt;

public:
  _const_iterator() : cnt(0) {}
  _const_iterator(_iterator it) : _it(it), cnt(0) {}
  _const_iterator(const _const_iterator &) = default;
  _const_iterator(_const_iterator &&) = default;
  _const_iterator &operator=(const _const_iterator &) = default;
  _const_iterator &operator=(_const_iterator &&) = default;

  using iterator_category = typename _iterator::iterator_category;
  using value_type = Kty;
  using difference_type = std::ptrdiff_t;
  using pointer = const value_type *;
  using reference = const value_type &;

  reference operator*() const { return _it->first; }

  pointer operator->() const { return &_it->first; }

private:
  void increment() {
    ++cnt;
    if (cnt == (*_it).second) {
      ++_it;
      cnt = 0;
    }
  }

  void decrement() {
    if (cnt > 0) {
      --cnt;
    } else {
      --_it;
      cnt = (*_it).second - 1;
    }
  }

public:
  _const_iterator &operator++() {
    increment();
    return *this;
  }

  _const_iterator operator++(int) {
    _const_iterator tmp = *this;
    increment();
    return tmp;
  }

  _const_iterator &operator--() {
    decrement();
    return *this;
  }

  _const_iterator operator--(int) {
    _const_iterator tmp = *this;
    decrement();
    return tmp;
  }

  bool operator==(const _const_iterator &rhs) const {
    return this->_it == rhs._it;
  }

  bool operator!=(const _const_iterator &rhs) const { return !(*this == rhs); }
};
template <typename Kt, class Ct = std::less<Kt>> class muitiset {
public:
  using key_type = Kt;
  using compare_type = Ct;

private:
  using _map = std::map<key_type, size_t, compare_type>;
  _map _count;

public:
  using const_iterator = _const_iterator<key_type>;
  using const_reverse_iterator =
      std::reverse_iterator<_const_iterator<key_type>>;

  const_iterator begin() const { return const_iterator(_count.begin()); }

  const_iterator end() const { return const_iterator(_count.end()); }

  const_reverse_iterator rbegin() const {
    return const_reverse_iterator(end());
  }

  const_reverse_iterator rend() const {
    return const_reverse_iterator(begin());
  }

  size_t count(const key_type &val) const noexcept {
    auto itr = _count.find(val);
    itr = _count.end() ? 0 : itr->second;
  }

  void insert(const key_type &val) noexcept { _count[val]++; }

  void erase(const key_type &val) noexcept {
    if (_count.count(val) == 1) {
      if (--_count[val] == 0) {
        _count.erase(val);
      }
    }
  }

  void clear() noexcept { _count.clear(); }

  size_t size() const noexcept { return _count.size(); }

  const_iterator lower_bound(const key_type &val) const {
    return const_iterator(_count.lower_bound(val));
  }

  const_iterator upper_bound(const key_type &val) const {
    return const_iterator(_count.upper_bound(val));
  }

  const_reverse_iterator rlower_bound(const key_type &val) const {
    return const_reverse_iterator(upper_bound(val));
  }

  const_reverse_iterator rupper_bound(const key_type &val) const {
    return const_reverse_iterator(lower_bound(val));
  }

  const_iterator max_element() const {
    if (_count.empty()) {
      return end();
    }
    auto tmp = _count.end();
    tmp--;
    return const_iterator(tmp);
  }

  const_iterator min_element() const {
    if (_count.empty()) {
      return end();
    }
    return begin();
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  int m = 1 << n;
  muitiset<int> cnt;
  REP(i, m) {
    int a;
    cin >> a;
    cnt.insert(a);
  }
  muitiset<int> now;
  {
    int c = *cnt.max_element();
    cnt.erase(c);
    now.insert(c);
  }
  REP(i, n) {
    muitiset<int> next;
    for (auto &&a : now) {

      auto c = cnt.lower_bound(a);
      if (c == cnt.begin()) {
        cout << "No" << endl;
        return 0;
      }
      c--;
      int b = *c;
      next.insert(b);
      cnt.erase(b);
    }
    for (auto &&a : now) {
      next.insert(a);
    }
    now = next;
  }
  cout << "Yes" << endl;
}

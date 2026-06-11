#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>

// Acknowledgement: Special thanks to kyomukyomupurin, who developed this
// template.
template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::pair<T, U>& p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
  int n = 0;
  for (auto e : vec) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::ostream& operator<<(std::ostream& os, const std::set<T>& st) {
  int n = 0;
  for (auto e : st) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T, class U>
std::ostream& operator<<(std::ostream& os, const std::map<T, U>& mp) {
  int n = 0;
  for (auto e : mp) os << (n++ ? ", " : "{") << e;
  return os << (n ? "}" : "{}");
}

template <class T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
  for (T& e : vec) is >> e;
  return is;
}

#ifdef LOCAL
#define debug(...) \
  std::cerr << "[" << #__VA_ARGS__ << "]: ", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void debug_out() { std::cerr << '\n'; }

template <class Head, class... Tail>
void debug_out(Head&& head, Tail&&... tail) {
  std::cerr << head;
  if (sizeof...(Tail) != 0) std::cerr << ", ";
  debug_out(std::forward<Tail>(tail)...);
}
using namespace std;
using int64 = long long;

void process(priority_queue<int64>& x1, priority_queue<int64>& x2, int& Z,
             int64& ans) {
  if (x1.size() > 0 && x2.size() > 0) {
    if (x1.top() >= x2.top()) {
      Z--;
      ans += x1.top();
      x1.pop();
    } else {
      Z--;
      ans += x2.top();
      x2.pop();
    }
  } else if (x1.size() == 0) {
    Z--;
    ans += x2.top();
    x2.pop();
  } else if (x2.size() == 0) {
    Z--;
    ans += x1.top();
    x1.pop();
  }
}

int main() {
  int X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  priority_queue<int64> p, q, r;
  int64 tmp;
  for (int i = 0; i < A; i++) {
    cin >> tmp;
    p.push(tmp);
  }
  for (int i = 0; i < B; i++) {
    cin >> tmp;
    q.push(tmp);
  }
  for (int i = 0; i < C; i++) {
    cin >> tmp;
    r.push(tmp);
  }
  int64 ans = 0;
  priority_queue<int64, vector<int64>, greater<int64>> a_b;
  for (int i = 0; i < X; i++) {
    ans += p.top();
    a_b.push(p.top());
    p.pop();
  }
  for (int i = 0; i < Y; i++) {
    ans += q.top();
    a_b.push(q.top());
    q.pop();
  }
  debug(ans);
  while (1) {
    if (r.size() == 0) break;
    if (r.top() < a_b.top()) break;
    ans += r.top() - a_b.top();
    r.pop();
    a_b.pop();
  }
  cout << ans << endl;
  return 0;
}
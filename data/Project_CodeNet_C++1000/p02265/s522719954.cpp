#include <bits/stdc++.h>
#define int long long
#define main signed main()
#define loop(i, a, n) for (int i = (a); i < (n); i++)
#define rep(i, n) loop(i, 0, n)
#define forever while (true)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prec(n) fixed << setprecision(n)
template<typename A> using V = std::vector<A>;
template<typename A> using F = std::function<A>;
template<typename A, typename B> using P = std::pair<A, B>;
using pii = P<int, int>;
using vi = V<int>;
using vd = V<double>;
using vs = V<std::string>;
using vpii = V<pii>;
using vvi = V<vi>;
using vvpii = V<vpii>;
constexpr int INF = sizeof(int) == sizeof(long long) ? 1000000000000000000LL : 1000000000;
constexpr int MOD = 1000000007;
constexpr double PI = acos(-1);
template<typename A, typename B> bool cmin(A &a, const B &b) { return a > b ? (a = b, true) : false; }
template<typename A, typename B> bool cmax(A &a, const B &b) { return a < b ? (a = b, true) : false; }
using namespace std;

template<typename InputIterator> constexpr std::string join(InputIterator first, InputIterator last, const std::string &sep) {
  if (first == last) return "";
  std::stringstream ss;
  ss << *(first++);
  for_each(first, last, [&](auto &x) { ss << sep << x; });
  return ss.str();
}

main {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  list<int> l;
  while (n--) {
    string cmd;
    cin >> cmd;
    int x;
    if (cmd == "insert" || cmd == "delete") cin >> x;
    if (cmd == "insert") l.push_front(x);
    if (cmd == "delete") {
      auto iter = find(all(l), x);
      if (iter != l.end()) l.erase(iter);
    }
    if (cmd == "deleteFirst") l.pop_front();
    if (cmd == "deleteLast") l.pop_back();
  }
  cout << join(all(l), " ") << endl;
}
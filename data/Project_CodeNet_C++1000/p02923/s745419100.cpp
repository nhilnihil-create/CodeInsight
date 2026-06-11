// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  int n; in(n);
  vector<ll> H(n);
  loop(i,0,n) in(H[i]);
  ll cur = H[0];
  int cnt = 0;
  int max_ = 0;
  loop(i,1,n) {
    if (cur >= H[i]) {
      max_ = max(++cnt, max_);
    } else {
      cnt = 0;
    }
    cur = H[i];
  }
  print(max_);
  return 0;
}

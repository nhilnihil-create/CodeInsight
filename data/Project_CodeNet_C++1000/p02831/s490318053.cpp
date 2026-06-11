// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

vector<int> B { 400, 800, 1200, 1600, 2000, 2400, 2800, 3200, 5000 };

int main() {
  ll a, b;in(a),in(b);
  print(lcm(a, b));
  return 0;
}

// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

// 1分で進む角度
// 1分 6度
// 60分 30度
// 180 = PI
// 360 = 2PI
typedef long double ld;
int main() {
  cout.precision(15); cout << fixed;
  ld a, b, h, m;
  in(a),in(b),in(h),in(m);
  ld alpha = (0.5 * (h*60+m) * M_PI) / 180;
  ld beta = (6.0 * m * M_PI) / 180;
  ld theta = alpha-beta;
  print(sqrt(a*a + b*b - 2 * a * b * cos(theta)));
  return 0;
}

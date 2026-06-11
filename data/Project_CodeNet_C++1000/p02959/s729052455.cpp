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
  vector<ll> A(n+1),B(n);
  loop(i,0,n+1) in(A[i]);
  loop(i,0,n) in(B[i]);
  
  ll ans = 0;
  loop(i,0,n) {
    ll &a1 = A[i]; ll &a2 = A[i+1]; ll &b = B[i];
    ll d = min(a1, b);
    a1 -= d; b -= d;
    ll d2 = min(a2, b);
    a2 -= d2; b -= d2;
    ans += d + d2;
  }
  print(ans);
  return 0;
}

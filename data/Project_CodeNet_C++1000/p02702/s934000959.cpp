// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  string s; in(s);
  int n = s.size();
  ll p = 2019;
  reverse(s.begin(), s.end());
  ll rem = 0;
  ll ten = 1;
  vector<ll> C(p+1, 0);
  C[rem]++;
  loop(i,0,n) {
    ll d = s[i]-'0';
    rem = (rem + (d * ten)) % p;
    C[rem]++;
    ten = (ten * 10) % p;
  }
  
  ll ans = 0;
  loop(i,0,p) {
    ans += (C[i]*(C[i]-1)) / 2;
  }
  print(ans);
  return 0;
}

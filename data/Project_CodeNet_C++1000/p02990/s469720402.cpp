// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v) { cout << v << endl; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

const ll MOD = 1000000007;

ll intpow(int a, ll n) {
  if (n == 0) return 1;
  ll x = intpow(a, n/2);
  x *= x;
  x %= MOD;
  if (n&1) { x *= a; x %= MOD; }
  return x;
}

ll inv(ll n) {
  return intpow(n, MOD-2);
}

ll com(int n, int k) {
  ll x = 1, y = 1;
  loop(i,0,k) {
    x *= n-i;
    x %= MOD;
    y *= i+1;
    y %= MOD;
  }
  
  return (x * inv(y)) % MOD;
}

int main() {
  int n, k; in(n),in(k);
  loop(i,1,k+1) {
    print((com(k-1, i-1) * com(n-k+1, i)) % MOD);
  }
  return 0;
}

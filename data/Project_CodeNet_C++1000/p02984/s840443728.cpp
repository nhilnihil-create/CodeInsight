// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v) { cout << v << endl; }
template <typename T> void in(T &v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

int main() {
  int n; in(n);
  vector<ll> A(n);
  loop(i,0,n) in(A[i]);
  ll sum = 0;
  loop(i,0,n) sum += A[i];
  ll b = sum;
  loop(i,0,n) if (i&1) b -= 2 * A[i];
  vector<ll> B { b };
  loop(i,1,n) B.push_back(2*A[i-1]-B[i-1]);
  loop(i,0,B.size()) {
    if (i!=0) cout << " ";
    cout << B[i];
  }
  cout << endl;
  return 0;
}

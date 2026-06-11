// C++ 14
#include <bits/stdc++.h>
using namespace std;
template <typename T>  ostream& operator<<(ostream& os, const vector<T>& v)  {  os << "[";  for (int i = 0; i < v.size(); ++i) {  os << v[i];  if (i != v.size() - 1)  os << ", ";  }  os << "]";  return os;  }
template <typename T> void print(T v, string s = "\n") { cout << v << s; }
template <typename T> void in(T& v) { cin >> v; }
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

/*
0 1 2 3
0 0 1 3 6
2つ選ぶ時
1, 2, 3, 4, 5
3つ選ぶ時
3, 4, 5, 6
4つ選ぶ時
6
連続したものは必ず作れる.
最小値と最大値が分かればmax-min+1
これは累積和でO(1)だな.
*/
const ll MOD = 1000000007;
int main() {
  int n,k;in(n),in(k);
  vector<ll> acc(n+2, 0);
  loop(i,0,n+1) acc[i+1] = acc[i] + i;
  ll ans = 0;
  loop(i,k,n+2) {
    // print(vector{ acc[n+1]-acc[n-i+1], acc[i]});
    ans += acc[n+1]-acc[n-i+1] - acc[i] + 1;
    ans %= MOD;
  }
  print(ans);
  return 0;
}

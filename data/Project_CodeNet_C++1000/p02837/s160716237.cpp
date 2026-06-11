// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

/*
bit全探索. 正直か無視か
正直の場合に正直ものとその証言をすべてチェックして矛盾しなければ正直の人数を更新.
*/
typedef pair<int, int> P;
int nth(ll S, int n) {
  return (S>>n)&1;
}
int main() {
  int n; cin >> n;
  vector<P> A[20];
  loop(i,0,n) {
    int a; cin >> a;
    loop(j,0,a) {
      int x, y; cin >> x >> y;
      x--;
      A[i].emplace_back(x, y);
    }
  }
  
  int max_ = 0;
  for (ll S=0; S<1<<n; S++) {
    bool ok = true;
    loop(i,0,n) {
      if (nth(S, i) == 0) continue;
      for (auto &&a: A[i]) {
        ok &= nth(S, a.first) == a.second;
      }
    }
    if (ok) max_ = max(max_, __builtin_popcount(S));
  }
  cout << max_ << endl;
  return 0;
}

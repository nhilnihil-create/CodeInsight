
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int vs[100000+10];
int inv[100000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &vs[i]);
    inv[vs[i]] = i;
  }
  ll res = 0;
  set<int> ss;
  for(int v = n; v > 0; --v) {
    auto it = ss.lower_bound(inv[v]);
    // 後のでかいの採用
    if(it != ss.end()) {
      ll i1, i2, i3, i4;
      i2 = inv[v];
      i3 = *it;
      if(it == ss.begin()) {
        i1 = -1;
      } else {
        i1 = *--it;
        ++it;
      }
      ++it;
      if(it == ss.end()) {
        i4 = n;
      } else {
        i4 = *it;
      }
      --it;
      // cerr << "R> " << v << ": " << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
      res += (i2-i1) * (i4-i3) * v;
    }
    // 前のでかいの採用
    if(it != ss.begin()) {
      ll i1, i2, i3, i4;
      i3 = inv[v];
      if(it == ss.end()) {
        i4 = n;
      } else {
        i4 = *it;
      }
      i2 = *--it;
      if(it == ss.begin()) {
        i1 = -1;
      } else {
        i1 = *--it;
        ++it;
      }
      // cerr << "L> " << v << ": " << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
      res += (i2-i1) * (i4-i3) * v;
    }
    ss.insert(inv[v]);
  }
  cout << res << endl;
  
  return 0;
}


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;
typedef long long ll;

int vs[1000000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  multiset<int> ss;
  REP(i, 1 << n) {
    int v;
    scanf("%d", &v);
    ss.insert(-v);
  }
  bool possible = true;
  vs[0] = *ss.begin();
  ss.erase(ss.begin());
  int ii = 1;
  REP(i, n) {
    REP(j, 1 << i) {
      auto it = ss.upper_bound(vs[j]);
      if(it == ss.end()) {
        // cerr << "> " << i << " " << j << " " << vs[j] << " " << endl;
        possible = false;
        goto OUT;
      }
      vs[ii++] = *it;
      ss.erase(it);
    }
  }
 OUT:
    // REP(i, 1 << n) {
    //   cerr << -vs[i] << " ";
    // }
    // cerr << endl;
    puts(possible ? "Yes" : "No");
  
  return 0;
}

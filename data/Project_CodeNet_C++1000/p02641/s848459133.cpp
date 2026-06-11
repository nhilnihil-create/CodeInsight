
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;


int main(void) {
  int x, n;
  cin >> x >> n;
  set<int> ss;
  REP(i, n) {
    int v;
    cin >> v;
    ss.insert(v);
  }

  for(int d = 0; ; ++d) {
    if(ss.count(x-d) == 0) {
      cout << x-d << endl;
      break;
    }
    if(ss.count(x+d) == 0) {
      cout << x+d << endl;
      break;
    }
  }

  return 0;
}

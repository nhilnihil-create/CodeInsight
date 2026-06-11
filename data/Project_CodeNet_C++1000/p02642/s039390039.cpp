
#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#define REP(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

int vs[200000+10];
bool isNotOK[1000000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &vs[i]);
  }
  sort(vs, vs + n);
  REP(i, n) {
    if(i > 0 && vs[i] == vs[i-1]) {
      isNotOK[vs[i]] = true;
      continue;
    }
    for(int j = vs[i]*2; j <= 1000000; j += vs[i]) {
      isNotOK[j] = true;
    }
  }
  int res = 0;
  REP(i, n) {
    if(!isNotOK[vs[i]]) {
      ++res;
    }
  }
  cout << res << endl;
  
  return 0;
}

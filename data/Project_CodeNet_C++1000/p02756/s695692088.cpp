
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;


char buf[100000+10];
int main(void) {
  list<char> res;
  int nQuery;
  scanf("%s%d", buf, &nQuery);
  int n = strlen(buf);
  REP(i, n) {
    res.push_back(buf[i]);
  }
  bool reversed = false;
  REP(iQuery, nQuery) {
    int t;
    scanf("%d", &t);
    if(t == 1) {
      reversed = !reversed;
    } else {
      int f;
      char ch;
      scanf("%d %c", &f, &ch);
      --f;
      if(!!f == !reversed) {
        res.push_back(ch);
      } else {
        res.push_front(ch);
      }
    }
  }
  if(reversed) {
    reverse(res.begin(), res.end());
  }
  for(char c : res) {
    printf("%c", c);
  }
  puts("");
  return 0;
}

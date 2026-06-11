#include <cassert>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;


int main(void) {
  string a, b, c;
  int x, y;
  cin >> a >> b >> x >> y >> c;
  if(a == c) {
    cout << x-1 << " " << y << endl;
  } else {
    cout << x << " " << y-1 << endl;
  }
  return 0;
}

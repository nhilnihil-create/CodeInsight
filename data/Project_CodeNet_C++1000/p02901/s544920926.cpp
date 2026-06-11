#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main() {
  long long n, m, x, y;
  cin >> n >> m;
  vector<long long> a(m), b(m);
  for(int i = 0; i < m; ++i){
    cin >> a[i];
    cin >> x;
    for(int j = 0; j < x; ++j){
      cin >> y;
      y--;
      b[i] |= 1 << y;
    }
  }
  long long nn = 1 << n;
  vector<long long> d(nn, 1e9);
  d[0] = 0;
  for(int i = 0; i < nn; ++i){
    if(d[i] == 1e9) continue;
    for(int j = 0; j < m; ++j){
      long long ii = i | b[j];
      d[ii] = min(d[ii], d[i] + a[j]);
    }
  }
  cout << (d[nn - 1] == 1e9? -1: d[nn - 1]);
}

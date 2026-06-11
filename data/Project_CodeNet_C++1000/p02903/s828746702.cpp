#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      if((j < a && i >= b) || (j >= a && i < b)) {
        cout << 1;
      } else {
        cout << 0;
      }
    }
    cout << endl;
  }
  return 0;
}
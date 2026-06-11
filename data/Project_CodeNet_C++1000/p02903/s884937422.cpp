#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
  int h, w, a, b;
  cin >> h >> w >> a >> b;
  rep(y, h) {
    rep(x, w) {
      if (x < a && y < b || x >= a && y >= b) cout << 0;
      else cout << 1;
    }
    cout << endl;
  }
  return 0;
}

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
  string s;
  cin >> s;
  int cnt = 1;
  string prev = s.substr(0, 1);
  int i = 1;
  while (i < s.size()) {
    for (int j = 1; j <= s.size() - i; j++) {
      string sub = s.substr(i, j);
      if (sub != prev) {
        prev = sub;
        cnt++;
        i += sub.size();
        break;
      }
      else if (i == s.size() - 1) {
        i++;
        break;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}

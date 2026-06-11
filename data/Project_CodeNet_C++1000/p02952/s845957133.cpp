#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <numeric>
using namespace std;

int main() {
  int N; cin >> N;

  int ans = 0;
  int i = 1;
  while (i <= N) {
    if (i == 10) {
      i = 100;
      continue;
    }
    if (i == 1000) {
      i = 10000;
      continue;
    }
    if (i == 100000) {
      break;
    }
    ++ans;
    ++i;
  }
  cout << ans << endl;

  return 0;
}

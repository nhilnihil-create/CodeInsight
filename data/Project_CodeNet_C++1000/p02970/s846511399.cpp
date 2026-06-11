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
  int N, D; cin >> N >> D;

  int ans = 1;
  for (int i = 2 * D + 2; i <= N; i += 2 * D + 1) {
    ++ans;
  }

  cout << ans << endl;

  return 0;
}

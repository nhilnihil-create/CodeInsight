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
  vector<int> w(N);
  for (int i = 0; i < N; i++) {
    cin >> w[i];
  }

  // sort(w.begin(), w.end());

  int sm = accumulate(w.begin(), w.end(), 0);

  int prev = w.front();
  sm -= prev;
  int ans = 1e9;
  for (int i = 1; i < N; i++) {
    ans = min(ans, abs(sm - prev));
    prev += w[i];
    sm -= w[i];
  }

  cout << ans << endl;
  return 0;
}

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

  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  int ans = 0;
  for (int i = 0; i + 2 < N; i++) {
    vector<int> s{p[i], p[i+1], p[i+2]};
    sort(s.begin(), s.end());
    if (s[1] == p[i+1])
      ++ans;
  }

  cout << ans << endl;

  return 0;
}

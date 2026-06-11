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
  int N, X; cin >> N >> X;

  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }

  int d = 0;
  int i = 0;
  int ans = 0;
  while (i < N) {
    if (d <= X)
      ++ans;
    d += L[i];
    i++;
  }
  if (d <= X)
    ++ans;
  cout << ans << endl;
  return 0;
}

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
  int N, L; cin >> N >> L;

  vector<int> apple(N);
  for (int i = 1; i <= N; i++) {
    apple[i-1] = L + i - 1;
  }

  int sum = accumulate(apple.begin(), apple.end(), 0);

  int ans = 1e9;
  int sm;
  for (int i = 0; i < N; i++) {
    int v = sum - apple[i];
    int d = abs(abs(sum) - abs(v));
    if (d < ans) {
      ans = d;
      sm = v;
    }
  }

  cout << sm << endl;

  return 0;
}

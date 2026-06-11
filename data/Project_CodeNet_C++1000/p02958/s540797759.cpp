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
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    int p; cin >> p;
    if (p != i)
      ++cnt;
    if (cnt > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;

  return 0;
}

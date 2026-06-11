#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;
using ll = long long;
const int INF = 1000000009;
const ll LINF = 1e18;

int n;

void dfs(string s, char mx) {
  if (s.size() == n) {
    cout << s << endl;
    return;
  }

  for (char c = 'a'; c <= mx + 1; c++) {
    string t = s;
    t += c;
    dfs(t, max(mx, c));
  }
}

int main() {
  cin >> n;
  dfs("", 'a' - 1);
}

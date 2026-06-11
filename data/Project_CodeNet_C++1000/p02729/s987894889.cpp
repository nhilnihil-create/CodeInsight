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

int main() {
  int n, m;
  cin >> n >> m;
  cout << n * (n - 1) / 2 + m * (m - 1) / 2 << endl;
}

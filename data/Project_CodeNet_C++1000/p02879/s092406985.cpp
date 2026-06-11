#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int a, b;
  cin >> a >> b;
  int ans = a * b;
  if (9 < a) ans = -1;
  if (9 < b) ans = -1;
  cout << ans << endl;
  return 0;
}
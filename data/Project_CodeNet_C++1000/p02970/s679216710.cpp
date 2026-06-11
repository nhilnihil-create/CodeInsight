#include <algorithm>
#include <cmath>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
  int N, D;
  cin >> N >> D;
  int ans = (N + D * 2) / (D * 2 + 1);
  cout << ans << endl;
  return 0;
}
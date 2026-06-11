#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    if (to_string(i).length() % 2 == 1) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
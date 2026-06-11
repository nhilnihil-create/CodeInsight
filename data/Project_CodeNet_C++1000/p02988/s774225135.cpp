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
  vector<ll> p(N);
  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }
  ll ans = 0;
  for (int i = 1; i < N - 1; i++) {
    if ((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
        (p[i + 1] < p[i] && p[i] < p[i - 1]))
      ans++;
  }
  cout << ans << endl;
  return 0;
}
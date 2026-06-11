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
  ll N, K, Q;
  cin >> N >> K >> Q;
  ll a;
  map<ll, ll> m;
  ll total = 0;
  for (int i = 0; i < Q; i++) {
    cin >> a;
    a--;
    m[a]++;
    total++;
  }
  for (int i = 0; i < N; i++) {
    if (0 < K - total + m[i]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;
typedef pair<LL, LL> P;

int main() {
  LL N, D, A; cin >> N >> D >> A;
  vector<P> X(N);
  vector<LL> carry(N + 1, 0);
  for (int i = 0; i < N; ++i) {
    int x; double h; cin >> x >> h;
    int atk = ceil(h/A);
    X[i] = {x, atk};
  }

  LL total_atk = 0;
  LL damage = 0;
  sort(X.begin(), X.end());

  vector<LL> pos(N);
  for (int i = 0; i < N; ++i) pos[i] = X[i].first;

  for (int i = 0; i < N; ++i) {
    damage -= carry[i];
    if (X[i].second <= damage) continue;
    X[i].second -= damage;

    total_atk += X[i].second;
    damage += X[i].second;
    LL last = X[i].first + 2 * D + 1;
    LL j = lower_bound(pos.begin(), pos.end(), last) - pos.begin();
    carry[j] += X[i].second;
  }
  cout << total_atk << endl;
}

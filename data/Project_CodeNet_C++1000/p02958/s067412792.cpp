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
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    cin >> p[i];
    if (p[i] != i + 1) cnt++;
  }
  if (cnt <= 2) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
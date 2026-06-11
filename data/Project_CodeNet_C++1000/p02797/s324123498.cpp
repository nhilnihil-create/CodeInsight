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
  ll N, K, S;
  cin >> N >> K >> S;
  vector<ll> ans(N);
  ll cnt = 0;
  for (int i = 0; i < N; i++) {
    if (cnt < K)
      ans[i] = S;
    else if (S < 1000000000)
      ans[i] = S + 1;
    else
      ans[i] = S - 1;
    cnt++;
  }
  cout << ans[0];
  for (int i = 1; i < N; i++) {
    cout << " " << ans[i];
  }
  cout << endl;
  return 0;
}
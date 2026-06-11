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
  ll N, K;
  string S;
  cin >> N >> K >> S;
  ll score = 0;
  for (int i = 0; i < N - 1; i++) {
    if (S[i] == S[i + 1]) score++;
  }
  ll ans = min(score + 2 * K, N - 1);
  cout << ans << endl;
  return 0;
}
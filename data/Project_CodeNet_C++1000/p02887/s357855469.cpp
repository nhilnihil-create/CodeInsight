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
  string S;
  cin >> N >> S;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    if (!(i + 1 < N && S[i] == S[i + 1])) ans++;
  }
  cout << ans << endl;
  return 0;
}
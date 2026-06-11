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
  ll N, A, B;
  cin >> N >> A >> B;
  ll ans;
  if (B % 2 != A % 2)
    ans = min(A - 1, N - B) + 1 + (B - A - 1) / 2;
  else
    ans = (B - A) / 2;
  cout << ans << endl;
  return 0;
}
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
  string S;
  cin >> S;
  vector<ll> ans_list(S.length() + 1, 0);
  for (int i = 0; i < S.length(); i++) {
    if (S[i] == '<') {
      ans_list[i + 1] = max(ans_list[i] + 1, ans_list[i + 1]);
    }
  }
  for (int i = S.length() - 1; i >= 0; i--) {
    if (S[i] == '>') {
      ans_list[i] = max(ans_list[i + 1] + 1, ans_list[i]);
    }
  }
  ll ans = 0;
  for (auto e : ans_list) {
    ans += e;
  }
  cout << ans << endl;
  return 0;
}
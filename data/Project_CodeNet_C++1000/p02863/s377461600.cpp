#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, T;
  cin >> N >> T;
  vector<pair<int, int>> AB(N);
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    AB[i] = {a, b};
  }
  sort(AB.begin(), AB.end());

  int maxT = T + 3000;
  vector<int> DP(maxT + 1, 0);
  int answer = 0;
  rep(i, N) {
    for (int j = T - 1; j >= 0; --j) {
      answer = max(answer, DP[j] + AB[i].second);
      DP[j + AB[i].first] = max(DP[j + AB[i].first], DP[j] + AB[i].second);
    }
  }
  cout << answer << endl;
  return 0;
}

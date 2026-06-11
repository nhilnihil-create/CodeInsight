#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int M;
  cin >> M;
  vector<P> work(N);
  for (int i = 0; i < N; i++) cin >> work[i].first >> work[i].second;
  sort(work.begin(),work.end());
  priority_queue<int, vector<int>, less<int>> Q;
  int ans = 0;
  int cnt = 0;
  for (int i = 0; i < M; i++) {
    while (0 == 0) {
      if (cnt == N) {
        break;
      }
      if (work[cnt].first <= i+1) {
        Q.push(work[cnt].second);
        cnt++;
      } else {
        break;
      }
    }
    if (!Q.empty()) {
      int money = Q.top();
      ans += money;
      Q.pop();
    }
  }
  cout << ans << endl;
  return 0;
}

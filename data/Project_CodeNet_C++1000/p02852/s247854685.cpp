#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M; cin >> N >> M;
  string S; cin >> S;
  const int INF = 1000000007;
  vector<int> dp(N+1, INF);
  dp.at(N) = 0;
  queue<int> q;
  q.push(0);
  for (int i = N-1; i >= 0; i--) {
    while (1) {
      if (q.size() == 0) { cout << -1 << endl; return 0; }
      if (q.front() != INF && q.size() <= M) break;
      q.pop();
    }
    if (S.at(i) == '0') dp.at(i) = q.front() + 1;
    q.push(dp.at(i));
  }
  vector<int> ans;
  int x = 0;
  int rest = dp.at(0);
  while (x < N) {
    rest--;
    int i = 1;
    while (dp.at(x+i) != rest) i++;
    ans.push_back(i);
    x += i;
  }
  for (int i = 0; i < ans.size(); i++) {
    if (i) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
}
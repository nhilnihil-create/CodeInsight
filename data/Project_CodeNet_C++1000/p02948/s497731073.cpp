#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;

  vector<vector<int>> jobs(m + 1);
  rep(i,n) {
    int a,b;
    cin >> a >> b;
    if(a > m) continue;
    jobs[a].push_back(b);
  }

  int answer = 0;
  priority_queue<int> que;
  for (int i = m - 1; i >= 0; i--) {
    // 現在i日の時にできる仕事
    for (auto &s : jobs[m - i]) {
      que.push(s);
    }

    if(!que.empty()) {
      answer += que.top();
      que.pop();
    }
  }
  cout << answer << '\n';
}

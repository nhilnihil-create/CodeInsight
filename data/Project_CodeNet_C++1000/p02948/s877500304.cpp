#include<bits/stdc++.h>
using namespace std;

int N,M;
int A[100000], B[10000];

signed main() {
  cin >> N >> M;
  vector<vector<int>> work(100000);
  for(int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    work[a].push_back(b);
  }

  priority_queue<int> q;
  int ans = 0;
  for(int day=1; day<=M; day++) {
    for(int w : work[day]) q.push(w);
    if(q.empty()) continue;
    ans += q.top(); q.pop();
  }
  cout << ans << endl;
}

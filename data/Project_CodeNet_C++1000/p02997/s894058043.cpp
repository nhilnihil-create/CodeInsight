#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
static const int INF (1<<30);

int main() {
  int N, K;
  cin >> N >> K;

  if (K > (N-1)*(N-2)/2) {
    cout << -1 << endl;
    return 0;
  }

  vector<vector<int>> ans(N);

  for (int i = 1; i < N; i++) {
    ans[0].push_back(i+1);
  }

  int now = (N-1)*(N-2)/2;
  int id = 1;
  while (now > K) {
    int cnt = ans[id].size();
    ans[id].push_back(cnt+id+2);
    now--;
    if ((cnt+1) == (N-id-1)) id++;
  }
  
  int cntE = 0;
  rep(i, N) {
    cntE += ans[i].size();
  }
  cout << cntE << endl;

  rep(i, N) {
    for (auto x : ans[i]) {
      cout << (i+1) << " " << x << endl;
    }
  }

  return 0;
}

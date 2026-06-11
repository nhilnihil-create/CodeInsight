#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 200020;

signed main() {
  int n,k;
  cin >> n >> k;

  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  vector<int> visited(N, 0);
  vector<int> path;
  path.push_back(1);

  int pos = 1;
  int cnt = 1;
  int once = 0;
  while(true) {
    visited[pos] = cnt;
    pos = a[pos];

    if(visited[pos] != 0) {
      once = visited[pos] - 1;
      break;
    }

    path.push_back(pos);
    cnt++;
  }

  int loop = path.size() - once;

  int answer = 0;
  if(k <= once) {
    answer = path[k];
  } else {
    k -= once;
    k = k % loop;
    answer = path[k + once];
  }
  cout << answer << endl;
  return 0;

}
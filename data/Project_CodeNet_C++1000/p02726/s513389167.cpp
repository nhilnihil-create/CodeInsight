#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ld = long double;

int main()
{
  int n, x, y;
  cin >> n >> x >> y;
  vector<int> res(n, 0);
  vector<int> connect[n + 1];
  for (int i = 1; i <= n; i++) {
    if (i - 1 >= 1) connect[i].push_back(i - 1);
    if (i + 1 <= n) connect[i].push_back(i + 1);
    if (x == i) connect[i].push_back(y);
    if (y == i) connect[i].push_back(x);
  }
  for (int i = 1; i < n; i++) {
    queue<int> que;
    int st = i;
    vector<int> pass(n + 1, 0);
    for (auto j : connect[st]) {
      que.push(j);
      pass[j] = pass[st] + 1;
      if (j > i) res[pass[j]]++;
    }
    while(que.size()) {
      st = que.front();
      que.pop();
      for (auto j : connect[st]) {
        if (pass[j] == 0) {
          que.push(j);
          pass[j] = pass[st] + 1;
          if (j > i) {
            res[pass[j]]++;
          }
        }
      }
    }
  }
  for (int i = 1; i < n; i++) {
    cout << res[i] << endl;
  }

  return 0;
}

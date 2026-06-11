#include <bits/stdc++.h>
using namespace std;

int main() {
  long n, m;
  cin >> n >> m;
  long h[n];
  for (long i = 0; i < n; i++) {
    cin >> h[i];
  }
  long a[m], b[m];
  unordered_map<long, vector<long>> connections;
  for (long i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    if (find(connections[a[i] - 1].begin(),
             connections[a[i] - 1].end(),
             b[i] - 1) == connections[a[i] - 1].end())
      connections[a[i] - 1].push_back(b[i] - 1);
    if (find(connections[b[i] - 1].begin(),
             connections[b[i] - 1].end(),
             a[i] - 1) == connections[b[i] - 1].end())
      connections[b[i] - 1].push_back(a[i] - 1);
  }
  
  long count = 0;
  for (long i = 0; i < n; i++) {
    bool flag = false;
    for (auto j : connections[i]) {
      if (h[j] >= h[i]) {
        flag = true;
        break;
      }
    }
    if (flag) continue;
    count++;
  }
  
  cout << count;
  
  return 0;
}
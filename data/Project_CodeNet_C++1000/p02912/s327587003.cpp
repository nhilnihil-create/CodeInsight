#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n, m;
  cin >> n >> m;
  priority_queue<int, vector<int>, less<int>> q;

  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    q.push(temp);
  }

  for (int i = 0; i < m; i++) {
    int a = q.top();
    q.pop();
    q.push(a / 2);
  }

  ll ans = 0;

  while (!q.empty()) {
    ans += q.top();
    q.pop();
  }
  cout << ans << endl;
}
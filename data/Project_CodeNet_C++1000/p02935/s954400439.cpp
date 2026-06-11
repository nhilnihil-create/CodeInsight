#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  priority_queue<double, vector<double>, greater<double>> que;
  rep(i, N) {
    int v;
    cin >> v;
    que.push(v);
  }
  while (!que.empty()) {
    double v1 = que.top();
    que.pop();
    if (que.empty()) {
      cout << v1 << endl;
      return 0;
    }
    double v2 = que.top();
    que.pop();
    que.push((v1 + v2) / 2);
  }
}
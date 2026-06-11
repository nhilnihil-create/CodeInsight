#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> h(n);
  vector<bool> f(n, true);
  for (int i = 0; i < n; ++i) cin >> h[i];

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    if (h[--a] <= h[--b]) f[a] = false;
    if (h[b] <= h[a]) f[b] = false;
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) if (f[i]) cnt++;
  cout << cnt << endl;
}

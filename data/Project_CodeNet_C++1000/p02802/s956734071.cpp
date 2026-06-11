#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int n, m;
  cin >> n >> m;

  vector<bool> flag(n, false);

  vector<int> pena(n, 0);

  for (int i = 0; i < m; i++) {
    int x;
    string y;

    cin >> x >> y;
    x--;

    if (y == "AC") {
      flag[x] = true;
    } else {
      if (!flag[x]) {
        pena[x]++;
      }
    }
  }

  int corr = 0, error = 0;

  for (int i = 0; i < n; i++) {
    if (flag[i]) {
      corr++;
      error += pena[i];
    }
  }

  cout << corr << " " << error << endl;
}

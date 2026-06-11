#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, m;

  vector<int> x, y;

  vector<vector<int>> c(m, vector<int>(3));

  cin >> a >> b >> m;

  int xmin = INT_MAX, ymin = INT_MAX, cmin = INT_MAX;

  for (int i = 0; i < a; i++) {
    int tmp;
    cin >> tmp;
    x.push_back(tmp);
    xmin = min(tmp, xmin);
  }

  for (int i = 0; i < b; i++) {
    int tmp;
    cin >> tmp;
    y.push_back(tmp);
    ymin = min(tmp, xmin);
  }

  for (int i = 0; i < m; i++) {
    int xtmp, ytmp, ctmp;
    cin >> xtmp >> ytmp >> ctmp;
    cmin = min(cmin, x.at(xtmp - 1) + y.at(ytmp - 1) - ctmp);
  }

  cout << min(xmin + ymin, cmin);

  return 0;
}
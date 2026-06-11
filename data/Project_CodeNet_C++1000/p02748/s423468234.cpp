#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> as(a);
  vector<int> bs(b);
  for (auto &v : as)
    cin >> v;
  for (auto &v : bs)
    cin >> v;

  int ans =
      *min_element(as.begin(), as.end()) + *min_element(bs.begin(), bs.end());

  for (int i = 0 ; i < m; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    ans = min(as[x-1] + bs[y-1] - c, ans);
  }

  cout << max(0, ans) << endl;

}

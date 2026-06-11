#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0;
  cin >> n;
  int a[n];
  vector<pair<int, bool>> x[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < a[i]; j++) {
      int tmp1;
      bool tmp2;
      cin >> tmp1 >> tmp2;
      x[i].push_back(make_pair(tmp1, tmp2));
    }
  }

  for (int tmp = 0; tmp < (1 << n); tmp++) {
    bitset<15> s(tmp);
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (s[i]) {
        for (int j = 0; j < x[i].size(); j++)
          if (s[x[i][j].first - 1] != x[i][j].second)
            flag++;
      }
    }
    if (flag == 0 && ans < s.count())
      ans = s.count();
  }
  cout << ans;
  return 0;
}
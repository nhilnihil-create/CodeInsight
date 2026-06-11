#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> ap, an, az;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a >= 0) {
      ap.push_back(a);
    } else {
      an.push_back(a);
    }
  }

  sort(ap.begin(), ap.end());
  sort(an.rbegin(), an.rend());

  int m;
  vector<pair<int, int>> ans;
  if (ap.size() > 0 && an.size() > 0) {
    while (ap.size() > 1) {
      ans.push_back({an.back(), ap.back()});
      an.back() -= ap.back();
      ap.pop_back();
    }
    while (an.size() > 1) {
      ans.push_back({ap.back(), an.back()});
      ap.back() -= an.back();
      an.pop_back();
    }
    m = ap.back() - an.back();
    ans.push_back({ap.back(), an.back()});
  } else {
    if (ap.size() > 0) {
      reverse(ap.begin(), ap.end());
      while (ap.size() > 2) {
        int x = ap.back();
        ap.pop_back();
        int y = ap.back();
        ap.pop_back();
        ap.push_back(x - y);
        ans.push_back({x, y});
      }
      int x = ap.back();
      ap.pop_back();
      int y = ap.back();
      ap.pop_back();
      m = y - x;
      ans.push_back({y, x});
    }
    if (an.size() > 0) {
      reverse(an.begin(), an.end());
      while (an.size() > 2) {
        int x = an.back();
        an.pop_back();
        int y = an.back();
        an.pop_back();
        an.push_back(x - y);
        ans.push_back({x, y});
      }
      int x = an.back();
      an.pop_back();
      int y = an.back();
      an.pop_back();
      m = x - y;
      ans.push_back({x, y});
    }
  }

  cout << m << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}
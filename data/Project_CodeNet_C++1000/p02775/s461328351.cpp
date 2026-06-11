#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  vector<int> d;
  for (int i = 0; i < s.size(); i++) {
    d.push_back(s[i] - '0');
  }
  reverse(d.begin(), d.end());

  int ret = 0;
  for (int i = 0; i < d.size(); i++) {
    if (d[i] >= 10) {
      if (i < d.size() - 1) {
        d[i + 1] += d[i] / 10;
      } else {
        d.push_back(d[i] / 10);
      }
      d[i] %= 10;
    }

    if (d[i] <= 4) {
      ret += d[i];
    } else if (d[i] == 5) {
      if (i < d.size() - 1 && d[i + 1] >= 5) {
        ret += (10 - d[i]);
        d[i + 1] += 1;
      } else {
        ret += 5;
      }
    } else if (d[i] <= 9) {
      ret += (10 - d[i]);
      if (i < d.size() - 1)
        d[i + 1] += 1;
      else
        d.push_back(1);
    }
  }
  cout << ret << endl;
}
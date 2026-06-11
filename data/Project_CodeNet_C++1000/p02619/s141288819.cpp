#include <bits/stdc++.h>
using namespace std;

int calc(const vector<vector<int>> &s, const vector<int> &c, const vector<int> &last, int day, int t) {
  int v = 0;
  v += s.at(day - 1).at(t);
  for (int i = 0; i < 26; i++) {
    if (i == t) continue;
    v -= c.at(i) * (day - last.at(i));
  }
  return v;
}

int main() {
  int d;
  cin >> d;
  vector<int> c(26), last(26);
  for (int i = 0; i < 26; i++) {
    cin >> c.at(i);
  }
  vector s(d, vector(26, 0));
  for (int i = 0; i < d; i++) {
    for (int j = 0; j < 26; j++) {
      cin >> s.at(i).at(j);
    }
  }
  int v = 0;
  for (int i = 0; i < d; i++) {
    int t;
    cin >> t;
    t--;
    v += calc(s, c, last, i + 1, t);
    cout << v << endl;
    last.at(t) = i + 1;
  }
}

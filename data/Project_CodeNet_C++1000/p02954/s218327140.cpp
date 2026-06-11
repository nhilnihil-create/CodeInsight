#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

vector<pair<char, int>> runLengthEncoding(string s) {
  vector<pair<char, int>> res;
  char cur = s.at(0);
  int cnt = 1;
  for (int i = 1; i < s.size(); i++) {
    if (cur == s.at(i)) {
      cnt++;
    } else {
      res.emplace_back(cur, cnt);
      cnt = 1;
      cur = s.at(i);
    }
    if (i == s.size() - 1) {
      res.emplace_back(cur, cnt);
    }
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  auto lr = runLengthEncoding(s);
//  // デバッグ出力
//  rep(i, lr.size()) {
//    cout << "<";
//    cout << lr.at(i).first << ", " << lr.at(i).second;
//    cout << ">" << endl;
//  }
  rep(i, lr.size() / 2) {
    pair<char, int> r = lr.at(i * 2);
    pair<char, int> l = lr.at(i * 2 + 1);
    int ll = ceil((double) r.second / 2) + floor((double) l.second / 2);
    int rr = ceil((double) l.second / 2) + floor((double) r.second / 2);
    rep(j, r.second - 1) {
      cout << 0 << " ";
    }
    cout << ll << " ";
    cout << rr << " ";
    rep(j, l.second - 1) {
      cout << 0 << " ";
    }
  }
  cout << endl;

  return 0;
}

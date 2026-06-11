#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  string s;
  cin >> s;

  // 1つ目
  int count = 1;
  vector<char> current = {s[0]};
  vector<char> tmp;
  // 2つ目以降
  for (int i = 1; i < s.size(); i++) {
    tmp.push_back(s[i]);
    // 同じなら区別ここで区切れないから次へ
    if (current.size() == tmp.size() && equal(current.begin(), current.end(), tmp.begin())) {
      continue;
    } else {
      current = tmp;
      tmp.clear();
      count++;
    }
  }
  cout << count << endl;

  return 0;
}

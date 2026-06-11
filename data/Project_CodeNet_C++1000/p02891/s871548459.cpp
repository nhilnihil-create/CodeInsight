#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

// 文字列に必要な区切り数を計算
ll getCount(const string &t) {
  vector<ll> continuousCountList;
  ll continuousCount = 1; // 連続している数
  char tmp = t[0];
  for (ll i = 1; i < t.size(); ++i) {
    if (t[i] == tmp) {
      continuousCount++;
    } else {
      if (continuousCount > 1) {
        continuousCountList.push_back(continuousCount);
      }
      tmp = t[i];
      continuousCount = 1;
    }
  }
  if (continuousCount > 0) {
    continuousCountList.push_back(continuousCount);
  }
  ll res = 0;
  for (int v : continuousCountList) {
    res += floor(v / 2);
  }
  return res;
}

int main() {
  string s;
  ll k;
  cin >> s >> k;
  // 通常
  ll one = getCount(s);
  ll two = getCount(s + s);
  ll diff = two - one * 2;
  // 文字が同じ
  bool same = true;
  for (int i = 0; i < s.size() - 1; ++i) {
    if (s[i] != s[i + 1]) {
      same = false;
      break;
    }
  }
  ll res;
  if (same) {
    // 全部同じ文字の時は特殊
    res = k * s.size() / 2;
  } else {
    res = one * k + (diff * (k - 1));
  }
  cout << res << endl;

  return 0;
}

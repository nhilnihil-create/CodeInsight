#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

const int ContestCount = 26;
int d;
vector<int> c;
vector<vector<int>> s;

int calcMinus(int dd, vector<int> &last) {
  dd++;
  int res = 0;
  rep(i, ContestCount) {
    res += c.at(i) * (dd - last.at(i));
  }
  return res;
}

int calcScore(int dd, int contest, vector<int> &last) {
  int score = 0;
  int plus = s.at(dd).at(contest);
  score += plus;
  last.at(contest) = dd + 1;
  // マイナス分の計算
  int minus = calcMinus(dd, last);
  score -= minus;
  return score;
}

int main() {
  // 入力処理
  cin >> d;
  c.resize(ContestCount);
  rep(i, ContestCount) cin >> c.at(i);
  s.resize(d, vector<int>(ContestCount));
  rep(i, d) {
    rep(j, ContestCount) {
      cin >> s.at(i).at(j);
    }
  }
  // B問題用の入力
  vector<int> t(d);
  rep(i, d) {
    cin >> t.at(i);
    t.at(i)--;
  }

  vector<int> last = vector<int>(ContestCount, 0);

  vector<int> v(d, 0);
  rep(dd, d) {
    // 前処理
    int score;
    if (dd == 0) {
      score = 0;
    } else {
      score = v.at(dd - 1);
    }
    // コンテスト開催
    int contest = t.at(dd);
    score += calcScore(dd, contest, last);
    v.at(dd) = score;
  }
  rep(i, d) {
    cout << v.at(i) << endl;
  }
  return 0;
}

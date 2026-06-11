#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007
#define chmax(a, b) a = max(a, b)

int main() {
  int h, w, m;
  cin >> h >> w >> m;
  map<int, int> bomb_cnt_h;
  map<int, int> bomb_cnt_w;
  set<pair<int, int>> bomb_place;
  int max_bomb_h = 0;
  int max_bomb_w = 0;

  REP(i, m) {
    int bh, bw;
    cin >> bh >> bw;
    chmax(max_bomb_h, ++bomb_cnt_h[bh]);
    chmax(max_bomb_w, ++bomb_cnt_w[bw]);
    bomb_place.insert({bh, bw});
  }
  vector<int> candidate_h;
  vector<int> candidate_w;
  for (auto tmp : bomb_cnt_h) {
    if (tmp.second == max_bomb_h) candidate_h.push_back(tmp.first);
  }
  for (auto tmp : bomb_cnt_w) {
    if (tmp.second == max_bomb_w) candidate_w.push_back(tmp.first);
  }

  for (auto tmp_h : candidate_h) {
    for (auto tmp_w : candidate_w) {
      if (bomb_place.find({tmp_h, tmp_w}) == bomb_place.end()) {
        cout << max_bomb_w + max_bomb_h << endl;
        return 0;
      }
    }
  }
  cout << max_bomb_w + max_bomb_h - 1 << endl;
  return 0;
}
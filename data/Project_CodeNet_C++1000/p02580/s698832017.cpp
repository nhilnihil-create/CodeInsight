#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
const double PI = 3.14159265358979323846;
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

int main(void) {
  int H, W, M;
  cin >> H >> W >> M;
  set<pair<int, int>> st;
  rep(i, M) {
    int tmpa, tmpb;
    cin >> tmpa >> tmpb;
    st.insert({tmpa, tmpb});
  }
  int hmax = 0, wmax = 0;
  map<int, int> hmp, wmp;
  for (auto tmp : st) {
    chmax(hmax, ++hmp[tmp.first]);
    chmax(wmax, ++wmp[tmp.second]);
  }
  vector<int> hmaxpos, wmaxpos;
  for (auto tmp : hmp) {
    if (hmax == tmp.second) hmaxpos.push_back(tmp.first);
  }
  for (auto tmp : wmp) {
    if (wmax == tmp.second) wmaxpos.push_back(tmp.first);
  }
  int ans = hmax + wmax - 1;
  for (auto h : hmaxpos) {
    if (ans >= hmax + wmax) break;
    for (auto w : wmaxpos) {
      if (st.find({h, w}) == st.end()) {
        ans = hmax + wmax;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
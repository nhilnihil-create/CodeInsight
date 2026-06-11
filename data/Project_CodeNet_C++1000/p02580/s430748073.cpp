#include <iostream>
#include <vector>
#include <set>
using namespace std;

int H, W, M;

int main() {
  cin >> H >> W >> M;
  vector<int> h(H), w(W);
  set<pair<int, int> > st;
  int maxH = 0, maxW = 0;
  
  for (int i = 0; i < M; i++) {
    int ih, iw;
    cin >> ih >> iw;
    --ih; --iw;
    st.insert({ih, iw});
    h[ih]++; w[iw]++;
    maxH = max(maxH, h[ih]);
    maxW = max(maxW, w[iw]);
  }
  
  // 最大値のリストを抽出
  vector<int> mhl, mwl;
  for (int i = 0; i < H; i++) {
    if (maxH == h[i]) mhl.push_back(i);
  }
  for (int i = 0; i < W; i++) {
    if (maxW == w[i]) mwl.push_back(i);
  }
  
  int ans = maxH + maxW - 1;
  // 交点に無いパターンがあればそれが答え
  for (int i = 0; i < mhl.size(); i++) {
    for (int j = 0; j < mwl.size(); j++) {
      if (st.find({mhl[i], mwl[j]}) == st.end()) {
        ans++;
        cout << ans;
        return 0;
      }
    } 
  }
  cout << ans;
}
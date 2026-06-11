#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

/*
まず素直に, 最も多く爆弾が置かれている行と列の交点に爆弾を置けば, 最も多く爆破できる.
このとき, 設置点に既に爆弾が置かれていた場合, (行*列)ではその地点を重複して数えてしまうので,
(行*列-1)が爆破できる数になる. 逆に, 最も多く爆弾が置かれている行と列の交点で, かつそこに爆弾
が置かれていない場所に爆弾を置けば, (行*列)個の爆弾を爆破でき, これが最大値となる.
*/

int main() {
  int h, w, m;
  cin >> h >> w >> m;
  vector<int> hs(h), ws(w);  // その行(列)に何個爆弾があるか
  set<P> s;
  rep(i, m) {
    int r, c;
    cin >> r >> c;
    --r; --c;
    hs[r]++; ws[c]++;
    s.emplace(r, c);  // 爆弾が置かれている地点の座標
  }
  
  int mh = 0, mw = 0;
  rep(i, h) mh = max(mh, hs[i]);  // 一行に置かれている爆弾数の最大値
  rep(j, w) mw = max(mw, ws[j]);  // 一列に置かれている爆弾数の最大値
  vector<int> mhs, mws;
  rep(i, h) if (hs[i] == mh) mhs.push_back(i);  // 最も多く爆弾が置かれている行
  rep(j, w) if (ws[j] == mw) mws.push_back(j);  // 最も多く爆弾が置かれている列
  
  int ans = mh + mw;  // 理論上の最大値. 最大行と最大列の交点で, そこに爆弾が置かれていない
  for (auto i : mhs) for (auto j : mws) {
    if (s.count(P(i, j))) continue;  // 交点に爆弾が置かれていたらcontinue
    cout << ans << endl;  // そうでなければ理論上の最大値が答え
    return 0;
  }
  
  // 最大行と最大列の交点で, そこに爆弾が置かれていないような地点がなかった場合
  cout << ans - 1 << endl;  
}
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

int main () {
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> va(a), vb(b), x(m), y(m), c(m);
  rep(i, a) cin >> va[i];
  rep(i, b) cin >> vb[i];
  rep(i, m) cin >> x[i] >> y[i] >> c[i];
  
  //割引券を使う場合
  int minPrice = va[x[0] - 1] + vb[y[0] - 1] - c[0];
  rep(i, m) {
    int price = va[x[i] - 1] + vb[y[i] - 1] - c[i];
    minPrice = min(minPrice, price);
  }
  
  //割引券を使わない場合
  sort(va.begin(), va.end());
  sort(vb.begin(), vb.end());
  int minPrice2 = va[0] + vb[0];
  
  //出力
  cout << min(minPrice, minPrice2) << endl;
}
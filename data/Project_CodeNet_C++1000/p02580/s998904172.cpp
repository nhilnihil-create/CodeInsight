#include <bits/stdc++.h>
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(0);
  int r,c,m;
  cin >> r >> c >> m;
  vector<int> h(m);
  vector<int> w(m);
  for (int i=0;i<m;i++) {
    cin >> h[i] >> w[i];
  }
  vector<int> bsh(r+1,0);
  vector<int> bsw(c+1,0);
  for (int i=0;i<m;i++) {
    bsh[h[i]]++;
    bsw[w[i]]++;
  }
  int bshmax = 0;
  int bswmax = 0;
  for (int i=0;i<=r;i++) {
    bshmax = max(bshmax,bsh[i]);
  }
  for (int i=0;i<=c;i++) {
    bswmax = max(bswmax,bsw[i]);
  }
  int hmaxs = 0;
  int wmaxs = 0;
  for (int i=0;i<=r;i++) {
    if (bsh[i] == bshmax) hmaxs++;
  }
  for (int i=0;i<=c;i++) {
    if (bsw[i] == bswmax) wmaxs++;
  }
  int cross = 0;
  for (int i=0;i<m;i++) {
    if (bsh[h[i]] == bshmax && bsw[w[i]] == bswmax) {
      cross++;
    }
  }
  if (cross == hmaxs*wmaxs) {
    cout << bshmax+bswmax-1 << endl;
  } else {
    cout << bshmax+bswmax << endl;
  }
}
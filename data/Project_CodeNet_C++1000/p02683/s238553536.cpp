#include<iostream>
using namespace std;
#include<algorithm>

int main() {
  int n, m, x;
  cin >> n >> m >> x;
  int bk[n][m+1];
  for(int i = 0; i < n; i++) {
    for(int j = 0; j <= m; j++) {
      cin >> bk[i][j];
    }
  }
  int res = 100000000, sk[m], tempres;
  bool flag;
  for(int bit = 0; bit < (1<<n); bit++) {
    tempres = 0;
    flag = true;
    for(int i = 0; i < m; i++) {
      sk[i] = 0;
    }
    for(int i = 0; i < n; i++) {
      if(bit & (1<<i)) {
        tempres += bk[i][0];
        for(int j = 0; j < m; j++) {
          sk[j] += bk[i][j+1];
        }
      }
    }
    for(int i = 0; i < m; i++) {
      if(sk[i] < x) flag = false;
    }
    if(flag) res = min(res, tempres);
  }
  switch (res) {
    case 100000000:
      cout << -1 << endl;
      break;
    default:
      cout << res << endl;
  }
  return 0;
}
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A&lang=jp
#include <iostream>

using namespace std;
const int KINDMAX = 21;
const int PAYMAX = 50001;
const int COINMAX = 10000;

int dp[PAYMAX][KINDMAX];
int coinMem[PAYMAX];
int main() {
  int pay, kind, coin[KINDMAX];
  cin >> pay >> kind;
  for (int i=0; i<kind; ++i) {
    cin >> coin[i];
  }

  for (int j=0; j<=pay/coin[0]; ++j) {
    dp[j*coin[0]][0] = j;
    if (kind==1) continue;
    //coinMod[ (j*coin[0])%(coin[1]) ]++;

  }
  for (int i=1; i<kind; ++i) {
    for (int j=0; j<=pay; ++j) {
      coinMem[j] = 0;
    }
    int dpi = i;
    for (int j=0; j<=pay/coin[i]; ++j) {
      dp[j*coin[i]][dpi] = j;
    }
    for (int j=1; j<=pay; ++j) {
      int back = j-coin[i];
      if (back > 0 && dp[back][dpi-1] != 0) {
        if (coinMem[back] == 0) {
          int q = dp[back][dpi-1] + 1;
          if (dp[j][dpi]==0 || q < dp[j][dpi]) dp[j][dpi] = q;
          coinMem[j] = q;
        } else {
          int q = dp[back][dpi-1] + 1;
          int r = coinMem[back] + 1;
          coinMem[j] = q<r? q:r;
          if (dp[j][dpi]==0 || coinMem[j] < dp[j][dpi]) dp[j][dpi] = coinMem[j];
        }
      }
      if (dp[j][dpi-1] != 0) {
        if (dp[j][dpi] != 0 && dp[j][dpi] < dp[j][dpi-1]) {
          continue;
        } else {
          dp[j][dpi] = dp[j][dpi-1];
        }
      }
    }
  }
  cout << dp[pay][kind-1] << endl;
/*
  for (int i=0; i<=pay; ++i) {
    for (int j=0; j<kind; ++j) {
      cerr << dp[i][j] << "\t";
    }
    cerr << endl;
  }
  */
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  double w, h;
  double pX, pY;
  double tmp1, tmp2;
  double kekka = 0.0000;
  double cnt = 0;
  cin >> w >> h >> pX >> pY;

  kekka = (w * h) / 2.0;
  if ((double)pX == (double)(w / 2) && (double)pY == (double)(h / 2)) cnt++;

  cout << setprecision(18) << kekka;
  cout << " ";
  if (cnt > 0) cout << 1;
  else cout << 0;

}

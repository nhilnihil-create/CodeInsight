#include <bits/stdc++.h>
using namespace std;
int main() {

  int h, m, H, M, k;
  cin >> h >> m >> H >> M >> k;

  cout << (H - h)*60 + (M - m) - k << endl;

}
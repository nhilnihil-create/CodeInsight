#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  double W, H, x, y;
  cin >> W >> H >> x >> y;
  cout << fixed << setprecision(10) << (H * W) / 2.0 << " " << ((x + x == W) && (y + y == H)) << endl;

  return 0;
}

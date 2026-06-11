#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  long double A, B, H, M;
  cin >> A >> B >> H >> M;
  long double degree = abs((H * 60 + M) / 720 * 360 - M / 60 * 360);
  long double rad = M_PI * degree / 180;
  cout << sqrt(pow(A, 2) + pow(B, 2) - 2 * A * B * cos(rad));
}

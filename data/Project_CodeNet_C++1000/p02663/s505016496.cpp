#include <bits/stdc++.h>
using namespace std;

int main() {
  int H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  int X1, X2, Xa;
  X1 = 60 * H1 + M1;
  X2 = 60 * H2 + M2;
  Xa = X2 - X1 - K;
  cout << Xa << endl;
}
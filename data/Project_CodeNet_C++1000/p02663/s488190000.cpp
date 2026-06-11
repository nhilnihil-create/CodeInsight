#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  int diff = (H2 - H1) * 60 + M2 - M1;
  cout << diff - K << endl;
  return 0;
}
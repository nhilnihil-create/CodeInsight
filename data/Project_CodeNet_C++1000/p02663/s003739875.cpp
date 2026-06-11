#include <bits/stdc++.h>
using namespace std;

int main() {
  int H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  M1 += H1 * 60, M2 += H2 * 60;
  cout << max(M2 - M1 - K, 0) << endl;
}

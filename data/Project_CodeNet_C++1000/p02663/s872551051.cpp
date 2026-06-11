#include <bits/stdc++.h>
using namespace std;

int main(void){
  int H1, M1, H2, M2, K, x;

  cin >> H1 >> M1 >> H2 >> M2 >> K;

  x = (H2 * 60 + M2) - (H1 * 60 + M1) - K;

  cout << x << endl;
}
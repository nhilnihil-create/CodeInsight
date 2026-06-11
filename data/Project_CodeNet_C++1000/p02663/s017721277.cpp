#include<bits/stdc++.h>

using namespace std;

int main() {
  int H1, M1, H2, M2, K;
  
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  
  int can = (H2 - H1) * 60 + M2 - M1;
  
  cout << (K <= can ? can - K : 0) << endl;
  
  return 0;
}
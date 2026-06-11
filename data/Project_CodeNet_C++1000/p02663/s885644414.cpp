#include <bits/stdc++.h>
using namespace std;

int main(){
  int H1, M1, H2, M2, K;
  cin >> H1 >> M1 >> H2 >> M2 >> K;
  int getup, sleep, limit;
  getup = 60 * H1 + M1;
  sleep = 60 * H2 + M2;
  limit = sleep - K;
  cout << limit - getup << endl;
  return 0;


}

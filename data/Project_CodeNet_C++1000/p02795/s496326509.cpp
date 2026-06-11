#include <bits/stdc++.h>
using namespace std;


int main(){
  int H, W, N;
  cin >> H >> W >> N;
  int max_HW = max(H, W);
  cout << N/max_HW + (N%max_HW==0?0:1) << endl;
  return 0;
}

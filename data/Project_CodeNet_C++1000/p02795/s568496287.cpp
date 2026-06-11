#include <iostream>
using namespace std;
int main(void){
  int H,W,N;
  cin >> H >> W >> N;
  
  int d = 0;
  if(H > W) d = H;
  else d = W;
  
  cout << (N + d - 1) / d << endl;
  
  return 0;
}

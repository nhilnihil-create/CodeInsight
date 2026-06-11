#include <iostream>

using namespace std;

int main(){
  long H, W;
  cin >> H >> W;
  
  long line[2]={(W+1L)/2L, W/2L};
  
  long cnt=0;
  
  if (H==1 || W==1) {
    cout << 1 << endl;
    return 0;
  }
  
  for (int i=0; i<H; i++) {
    cnt += line[i%2];
  }
  
  cout << cnt << endl;
  return 0;
}
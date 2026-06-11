#include <iostream>
using namespace std;

int main(){
  int H, W, N;
  cin >> H >> W >> N;
  
  int k = max(H, W);
  int ans;
  
  if (N % k == 0){
    ans = N / k;
  }
  else {
    ans = (N / k) + 1;
  }
  
  cout << ans << endl;
  
  return 0;
}
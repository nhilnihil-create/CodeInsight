#include <iostream>

using namespace std;

int main(){
  int W, H;
  int N;
  int tmp;
  int cnt = 0;
  
  cin >> W;
  cin >> H;
  cin >> N;
  
  if(W <= H){
    tmp = H;
  }
  else{
    tmp = W;
  }
  
  while(N > 0){
    N -= tmp;
    cnt++;
  }
  
  cout << cnt << endl;
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int64_t N;
  cin >> N;
  
  int64_t Y, X = 100;
  int cnt = 0;
  
  while(X <= 1000000000000000000){
    if(X >= N){
      break;
    }
    cnt++;
      Y = X / 100;
      X += Y;
  }
  
  cout << cnt << endl;
  
  return 0;
}

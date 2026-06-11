#include<bits/stdc++.h>
using namespace std;

int main(void){
  int H, A, _A;
  int cnt = 0;
  cin >> H >> A;
  while(1){
    cnt++;
    _A = A * cnt;
    if(_A >= H){
      cout << cnt << "\n";
      break;
    }
  }
  return 0;
}

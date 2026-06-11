#include<bits/stdc++.h>
using namespace std;

int main(void){
  int N, cnt;
  bool ans = false;
  cin >> N;
  for(int i = 0; i < 3; i++){
    cnt = N % 10;
    if(cnt == 7){
      ans = true;
      break;
    }
    N = N / 10;
  }
  if(ans) cout << "Yes" << "\n";
  else cout << "No" << "\n";
  return 0;
}
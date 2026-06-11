#include<bits/stdc++.h>
using namespace std;

int main(void){
  int K, A, B, cnt;
  bool ans = false;
  cin >> K >> A >> B;
  cnt = B / K;
  for(int i = 1; i <= cnt; i++){
    if(A <= i * K && i * K <= B){
      ans = true;
      break;
    }
  }
  if(ans) cout << "OK" << endl;
  else cout << "NG" << endl;
  return 0;
}
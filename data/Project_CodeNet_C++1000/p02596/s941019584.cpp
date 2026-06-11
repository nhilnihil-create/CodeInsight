#include <bits/stdc++.h>
using namespace std; 

int main(){
  int a;
  cin >> a;
  int ans = -1;
  int now = 7%a;
  for(int i = 0; i <= a; i++){
    if (now % a == 0){
      ans = i+1;
      break;
    }
    now = now*10+7;
    now %= a;
  }
  cout << ans << endl;
}
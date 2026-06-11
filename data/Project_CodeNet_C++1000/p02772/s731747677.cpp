#include <bits/stdc++.h>
using namespace std;

int main(){
  int num;
  int x;
  bool chk = true;
  cin >> num;
  
  for(int i = 0; i < num; i++){
    cin >> x;
    if(x % 2 == 1) continue;
    else{
      if(x % 3 == 0 || x % 5 == 0) continue;
      else chk = false;
    }
  }
  
  if(chk == true) cout << "APPROVED";
  else cout << "DENIED";
}

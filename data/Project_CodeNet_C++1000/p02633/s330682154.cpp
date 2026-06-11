#include<bits/stdc++.h>
using namespace std;
int main(){
  int x; cin >> x;
  int cnt = 1;
  int kaku = x;
  while(1){
    if(kaku == 0){
      cout << cnt << endl;
      return 0;
    }
    cnt++;
    kaku += x;
    if(kaku >=360)
      kaku -= 360;
  }
}
      
#include <bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin >> x;
  
  int ths{x}, ans{1};
  while(ths != 0){
    ths = (ths + x)%360;
    ans++;
  }
  cout << ans << endl;
}
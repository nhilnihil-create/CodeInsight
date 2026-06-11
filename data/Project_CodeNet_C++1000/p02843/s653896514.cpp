#include <iostream>
#include <algorithm>
using namespace std;
int main(){
  int x;
  cin >> x;
  int cnt = 0;
  while(x-100>=0){
    x -= 100;
    cnt++;
  }
  if(cnt*5>=x) cout << 1 << "\n";
  else cout << 0 << "\n";
  return 0;
}

#include <iostream>
using namespace std;
int main(void){
  int x,y;
  cin >> x >> y;
  
  int ans;
  
  if(x < 4) ans += (4 - x) * 100000;
  if(y < 4) ans += (4 - y) * 100000;
  
  if(x == 1 && y == 1) ans += 400000;
  
  cout << ans << endl;
  
  return 0;
}

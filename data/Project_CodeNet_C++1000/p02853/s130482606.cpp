#include <iostream>
#include <string>

using namespace std;

int main(){
  int x,y;
  cin >> x >> y;
  int a = 0;
  if(x == 1)a = 300000;
  else if(x == 2)a = 200000;
  else if(x == 3)a = 100000;
  else a = 0;
  int b = 0;
  if(y == 1)b = 300000;
  else if(y == 2)b = 200000;
  else if(y == 3)b = 100000;
  else b = 0;
  int ans = a + b;
  if(x == 1 && y == 1)cout << ans + 400000 << endl;
  else cout << ans << endl;
}

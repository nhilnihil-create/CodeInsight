#include <iostream>
using namespace std;

int main(void){
  int x,n;
  
  cin >> x;
  n = x/100;
  x %= 100;
  if (x<=n*5) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}

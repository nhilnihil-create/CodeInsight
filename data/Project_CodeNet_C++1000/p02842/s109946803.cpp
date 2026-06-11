#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
  int X;
  cin >> X;
  int apple = ceil(X / 1.08f);
  int price = floor(apple * 1.08);
  if(X == price) cout << apple << endl;
  else cout << ":(" << endl;
  return 0;
}

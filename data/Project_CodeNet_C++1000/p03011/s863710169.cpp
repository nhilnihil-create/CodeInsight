#include <iostream>
#include <string>
using namespace std;
 
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int x = a + b;
  int y = b + c;
  int z = c + a;
  int min = x;
  if (min > y)
    min = y;
  if (min > z)
    min = z;
  cout << min;
}
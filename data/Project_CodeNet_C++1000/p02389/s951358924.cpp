#include <iostream>
using namespace std;

int main(void){
  int a = 0, b = 0, s = 0;
  cin >> a >> b;
  s = a * b;
  a = 2*a + 2*b;
  cout << s << " " << a << endl;
  return 0;
}
#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  
  string str_a(b, '0' + a);
  string str_b(a, '0' + b);
  
  if (str_a < str_b) {
    cout << str_a << endl;
  } else {
    cout << str_b << endl;
  }
  return 0;
}

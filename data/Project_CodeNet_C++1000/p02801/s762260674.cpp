#include <iostream>
using namespace std;

int main() {
  char c; cin >> c;
  int a = static_cast <int> (c) + 1;
  c = static_cast <char> (a);
  cout << c;
  
  return 0;
}
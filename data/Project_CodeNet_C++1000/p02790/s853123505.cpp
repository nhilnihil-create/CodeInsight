#include <iostream>
#include <string>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  string s;
  if (a >= b) {
    for (int i = 0; i < a; i++) {
      s += to_string(b);
    }
  } else {
    for (int i = 0; i < b; i++) {
      s += to_string(a);
    }
  }
  cout << s << endl;
}
#include <iostream>

using namespace std;

int main() {
  bool flag = false;
  char last = 'a';
  for (int i = 0; i < 4; ++i) {
    char d;
    cin >> d;
    if (last == d)
      flag = true;
    last = d;
  }
  cout << (flag ? "Bad" : "Good") << endl;
}
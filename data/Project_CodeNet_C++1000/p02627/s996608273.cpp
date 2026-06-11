#include <iostream>
using namespace std;
int main() {
  char c;
  cin >> c;
  if (islower(c)) {
    cout << 'a';
  } else {
    cout << 'A';
  }
}
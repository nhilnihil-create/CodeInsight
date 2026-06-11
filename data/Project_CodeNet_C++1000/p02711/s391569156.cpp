#include <iostream>

using namespace std;

int main() {
  char N[4] = {};
  for (int i = 0; i < 3; ++i) {
    cin >> N[i];
  }
  for (int i = 0; i < 3; ++i) {
    if (N[i] == '7') {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
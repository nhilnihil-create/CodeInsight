#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;
  for (char i : s) {
    char c;
    cin >> c;
    if (i != c) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}

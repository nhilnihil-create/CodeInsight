#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int d = s.back() - '0';
  switch (d) {
    case 0:
    case 1:
    case 6:
    case 8:
      cout << "pon" << endl;
      break;
    case 3:
      cout << "bon" << endl;
      break;
    default:
      cout << "hon" << endl;
  }
  return 0;
}

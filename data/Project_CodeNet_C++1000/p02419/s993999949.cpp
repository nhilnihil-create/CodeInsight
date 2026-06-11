#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
  string in, s;
  int i = 0,j = 0;
  cin >> s;

  while (cin >> in) {
    if (in == "END_OF_TEXT") {
      break;
    }

    for (j = 0; j < in.size(); j++) {
      in[j] = tolower(in[j]);
    }

    if (s == in) {
      i++;
    }
  }
  cout << i << endl;
  return 0;
}
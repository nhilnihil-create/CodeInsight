#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  if (s[1] == 'B')
    s[1] = 'R';
  else
    s[1] = 'B';
  cout << s << endl;
  return 0;
}

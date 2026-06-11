#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[]) {
  string s, t;
  cin >> s >> t;
  int count = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == t[i])
      count++;
  }
  cout << count << endl;
  return 0;
}

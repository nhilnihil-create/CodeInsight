#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int n = (int)s.size();
  for (int i=0; i<n; i+=2) {
    if (i == n-1 || s.at(i) != 'h' || s.at(i+1) != 'i') {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}

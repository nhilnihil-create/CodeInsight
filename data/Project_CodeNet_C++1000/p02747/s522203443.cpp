#include <iostream>
#include <string>
using namespace std;
int main() {
  string s; cin >> s;
  if(s.size() % 2 == 1) {
    cout << "No" << endl;
  } else {
    for(int i = 0; i < s.size(); i++) {
      if(i % 2 == 0) {
        if(s[i] != 'h') {
          cout << "No" << endl;
          return 0;
        }
      } else {
        if(s[i] != 'i') {
          cout << "No" << endl;
          return 0;
        }
      }
    }
    cout << "Yes" << endl;
  }
  return 0;
}

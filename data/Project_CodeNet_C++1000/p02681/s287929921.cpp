#include <iostream>
#include <string>

using namespace std;
int main() {
  string S;
  string T;
  cin >> S >> T;
  T.pop_back();
  if (S==T) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }

}
#include <iostream>
#include <string>
using namespace std;
int main() {
  int n;
  string str;
  cin >> n >> str;
  if(str.size() <= n) cout << str << endl;
  else {
    str = str.substr(0, n);
    cout << str << "..." << endl;
  }
  return 0;
}
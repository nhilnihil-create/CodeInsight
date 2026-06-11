#include <iostream>
#include <string>

using namespace std;

int main() {
  while (1) {
    string n;
    int sum = 0;
    cin >> n;
    if (n == "0") break;
    int i = n.length();
    while (i) {
      i--;
      sum += n[i]-'0';
    }
    cout << sum << endl;
  }
  return 0;
}
#include <iostream>
using namespace std;

int main() {
  int x; cin >> x;
  int count = 0, deg = 0;
  while(true) {
    if(deg > 0 && deg % 360 == 0) {
      cout << count << endl;
      return 0;
    }
    count++;
    deg += x;
  }
  return 0;
}

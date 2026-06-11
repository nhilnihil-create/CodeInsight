#include <iostream>

using namespace std;

int main() {
  int x, y;
  cin >> x >> y;
  
  for (int tsuru = 0; tsuru <= x; tsuru++) {
    if (tsuru*2 + (x - tsuru)*4 == y) {
      cout << "Yes";
      return 0;
    }
  }
  
  cout << "No";
  
  return 0;
}
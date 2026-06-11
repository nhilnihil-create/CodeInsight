#include <iostream>
using namespace std;

int main() {
  int x;
  for (int i = 0; i < 5; ++i) {
  	cin >> x;
    if (!x) {
   	  cout << i + 1;
      break;
    }
  }
  return 0;
}
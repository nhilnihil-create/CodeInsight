#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int bill = 1000;
  while (bill < n) bill += 1000;
  cout << bill - n << endl;
}

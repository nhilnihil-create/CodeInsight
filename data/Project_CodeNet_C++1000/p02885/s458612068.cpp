#include<iostream>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  if (A <= 2 * B) {
    cout << 0;
  }
  else {
    cout << A - 2 * B;
  }
}
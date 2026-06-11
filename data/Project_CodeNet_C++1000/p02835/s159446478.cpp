#include<iostream>
using namespace std;

int main() {
  int A1, A2, A3;
  cin >> A1 >> A2 >> A3;
  int sum = 0;
  sum = A1 + A2 + A3;
  if (sum > 21) {
    cout << "bust";
  }
  else {
    cout << "win";
  }
}
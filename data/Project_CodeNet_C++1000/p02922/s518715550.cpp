#include <iostream>
using namespace std;
 
int main() {
  int A, B;
  cin >> A >> B;
  int TapNumber = 1;
  int PlugNumber = A;
  
  //if (B == 1) cout << 0 << endl;
  //else if (A >= B) cout << 1 << endl;
  //else {

  while (PlugNumber < B) {
    PlugNumber += A - 1;
    TapNumber++;
  }
    
  if (B == 1) cout << 0 << endl;
  else cout << TapNumber << endl;
}

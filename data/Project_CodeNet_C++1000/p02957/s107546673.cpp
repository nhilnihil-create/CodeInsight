#include<iostream>
using namespace std;

int main() {
  long long A, B;
  cin >> A >> B;
  
  if ((A + B) % 2 == 1) cout << "IMPOSSIBLE" << endl;
  else cout << (A + B) / 2 << endl;
}
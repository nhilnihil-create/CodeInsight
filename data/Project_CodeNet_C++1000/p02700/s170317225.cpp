#include <iostream>

using namespace std;

bool solve(int A, int B, int C,	int D) {
  while(true) {
    C -= B;
    if(C <= 0) return true;
    A -= D;
    if(A <= 0) return false;
  }
  return true;
}

int main() {
  int A, B, C, D; cin>>A>>B>>C>>D;
  cout << (solve(A, B, C, D) ? "Yes" : "No") << endl;
  return 0;
}

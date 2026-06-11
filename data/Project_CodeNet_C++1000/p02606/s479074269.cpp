#include <iostream>
#define rep(i, n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
  int L, R, d;
  cin >> L >> R >> d;
  
  cout << (R / d) - ((L - 1) / d);
}

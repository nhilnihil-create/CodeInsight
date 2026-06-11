#include <bits/stdc++.h>
using namespace std;
int main() {
  int X,A;
  cin >> X;
  for(int i = 2;i < X;i++) {
    A = X % i;
    if(A == 0) {
      i = 2;
      X++;
    }
    
  }
  cout << X << endl;
}

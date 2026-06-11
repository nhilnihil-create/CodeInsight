#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
  int Y = X/100;
  int Z = X%100;
  if(Y*5 >= Z){
    cout << 1 << endl;
    return 0;
  }
  cout << 0 << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
  
  string S, T;
  cin >> S >> T;
  
  int m=0;
  for (int i = 0; i < 3; i++) {
    if (S.at(i) == T.at(i)) {
      m++;
    }
  }
  
  cout << m << endl;

return 0;
}
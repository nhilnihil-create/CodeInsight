#include <bits/stdc++.h>
using namespace std;

int main() {
  long X, Y;
  string ans = "No";
  cin >> X >> Y;
  
  if (Y%2 == 1) ans = "No";
  if (X*4 < Y) ans = "No";
  if (Y%2 ==0 && 2*X == Y) ans = "Yes"; 
  if (Y%4 ==0 && 4*X == Y) ans = "Yes"; 
  if (X*2 <= Y && X*4 > Y) {
    for (int i = 0; i < X; i++) if (i*2 + (X-i)*4 == Y) ans = "Yes";
  }
  
  cout << ans << endl;
}
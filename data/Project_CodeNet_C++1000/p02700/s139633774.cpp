#include <bits/stdc++.h>
using namespace std;

int main() {
  long A, B, C, D;
  string ans = "";
  cin >> A >> B >> C >> D;
  
  while (A > 0 && C > 0){
    C = C - B;
    if (C <= 0) {
      ans = "Yes";
      break;
    }
    A = A - D;
    if (A <= 0) {
      ans = "No";
      break;
    }
  } 
  
  cout << ans << endl;
}
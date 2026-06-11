#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  //cout << K << A << B <<endl;
  int C=1;
  string ans ="NG";
  
  while (K*C <= B) {
    if (A <= K*C && K*C <= B) {
      ans = "OK";
      break;
    }
    C++;
  }
  
  cout << ans << endl;

}
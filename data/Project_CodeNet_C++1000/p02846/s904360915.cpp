#include <bits/stdc++.h>
using namespace std;
int main () {
  long T1, T2, A1, A2, B1, B2;
  cin >> T1 >> T2 >> A1 >> A2 >> B1 >> B2;
  A1 -= B1;
  A2 -= B2;
  if(A1 * T1 + A2 * T2 == 0){
    cout << "infinity" << endl;
  } else {
    if((A1 < 0 && A2 < 0) || (A1 > 0 && A2 > 0))cout << 0 << endl;
    else {
      if(abs(A1 * T1) > abs(A2 * T2))cout << 0 << endl;
      else {
        if(abs(A1 * T1) % (abs(A2 * T2) - abs(A1 * T1)) == 0)cout << (abs(A1 * T1) + (abs(A2 * T2) - abs(A1 * T1)) - 1) / (abs(A2 * T2) - abs(A1 * T1)) * 2<< endl;
        else cout << (abs(A1 * T1) + (abs(A2 * T2) - abs(A1 * T1)) - 1) / (abs(A2 * T2) - abs(A1 * T1)) * 2 - 1<< endl;
      }
    }
  }
  return 0;
}
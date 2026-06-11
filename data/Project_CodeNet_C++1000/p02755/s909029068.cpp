#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int A,B;
  cin >> A >> B;
  for(int i=0;i<110000;i++){
    if( A/0.08<=i && i<(A+1)/0.08 && B/0.1<=i && i<(B+1)/0.1 ){
//      cout << A/0.08 << " : " << (A+1)/0.08 << " : " << B/0.1 << " : " << (B+1)/0.1 << endl;
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B,K;
  cin >> A >> B >> K;
  if(A+B <= K){
    cout << "0 0" << endl;
    return 0;
  }
  else if(K<A){
    cout << A-K << " " << B << endl;
    return 0;
  }
  else{
    cout << 0 << " " << B-(K-A) << endl;
    return 0;
  }
}
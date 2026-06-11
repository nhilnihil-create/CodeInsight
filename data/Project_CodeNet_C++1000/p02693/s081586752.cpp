#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int K, A, B;
  cin >> K >> A >> B;
  
  if(A%K != 0) {
    if(B >= (A/K+1)*K) cout << "OK" << endl;
    else cout << "NG" << endl;
  }
  
  else cout << "OK" << endl;
  
}
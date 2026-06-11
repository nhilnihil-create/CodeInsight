#include <bits/stdc++.h>
using namespace std;

int main() {
  
  bitset<1000000> DivL;
  
  int N;
  cin >> N ;
  
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  int n = A.at(0);
  
  for (int i = 1; i < N; i++) {
    n = gcd(n,A.at(i));
  }
  if (n > 1) {
    cout << "not coprime" << endl;
    goto end;
  }
  

  for (int i = 0; i < N; i++) {
    if (A.at(i) != 1 && DivL.test(A.at(i)-1)) {
      cout << "setwise coprime" << endl;
      goto end;
    }
    DivL.set(A.at(i)-1);
    for (int j = 2; j*j < A.at(i); j++) {
      if (A.at(i) % j == 0) {
        if (DivL.test(j-1)) {
          cout << "setwise coprime" << endl;
          goto end;
        }
        if (DivL.test(A.at(i)/j-1)) {
          cout << "setwise coprime" << endl;
          goto end;
        }
        DivL.set(j-1);
        DivL.set(A.at(i)/j-1);
      }
    }
  }
  
  cout << "pairwise coprime" << endl;
  
  end:
  return 0;
}
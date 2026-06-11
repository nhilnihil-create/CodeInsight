#include <bits/stdc++.h>
using namespace std;

int main() {
  string S,T,U; 
  int A, B;
  cin >> S >> T >> A >> B >> U;
  if(S==U) A-=1;
  if(T==U) B-=1;
  cout << A << " " << B << endl;
}
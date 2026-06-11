#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int64_t A,B,M;
  cin >> A >> B >> M;
  M -= A;
  if (M >= 0) {
   cout << "0 "; 
  }
 else {
  M += A;
   A -= M;
     cout << A << " ";
  M = 0;
 }
  M -= B;
  if (M >= 0) {
   cout << "0" << endl; 
  }
 else {
  M += B;
   B -= M;
     cout << B << endl;
 }
}
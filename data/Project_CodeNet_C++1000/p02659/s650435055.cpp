#include <bits/stdc++.h>
using namespace std;

int main() {
  long long  int A;
  double B;
  cin >> A >> B;

  
  long long int C = B*100+0.1;

  
  A = A * C;
  A /= 100;
  
  cout << A << endl;
  
 	
  
}

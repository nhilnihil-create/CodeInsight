#include <bits/stdc++.h>
using namespace std;

int main() { 
  int64_t a, b, k, A, B;
  cin >> a >> b >> k;
  if (k>=a+b) {
    A=0;
    B=0;
  }
  else if (k>=a) {
    A=0;
    B=b-(k-a);
  }
  else {
    A=a-k;
    B=b;
  }
  cout << A << " " << B << endl;
} 
#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A;
  double B;
  cin >> A >> B;
  int C = B * 100 + 0.001;
  long long D = A*C;
  cout << D/100 << endl;
}
  
  
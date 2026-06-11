#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int64_t A, B, C, D; cin >> A >> B >> C >> D;
  
  int64_t numberA = 0, numberB = 0, lcm = C / __gcd(C, D) * D;
  
  numberA = (A - 1) - ((A - 1) / C + (A - 1) / D - (A - 1) / lcm);
  
  numberB = B - (B / C + B / D - B / lcm);
  
  cout << numberB - numberA << endl;
  
}
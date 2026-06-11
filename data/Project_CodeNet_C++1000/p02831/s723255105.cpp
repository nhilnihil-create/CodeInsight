#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A,B;
  cin >> A >> B;
  long long mul = 1;
  
  for (int i = 2; i <= 100000; i++) {
    if (A % i == 0 && B % i == 0){
      A = A/i;
      B = B/i;
      mul *= i;
      i = 1;
    }
  }
  long long MM = A*B*mul;
  cout << MM << endl;
}
#include <bits/stdc++.h>
using namespace std;

long long gcd (long long a, long long b) {
  long long d=a;
  if (b!=0) {
    d=gcd(b, a%b);
  }
  return d;
}

int main() {
  long long A, B;
  cin >> A >> B;
  long long d=gcd(A,B);
  cout << A/d*B << endl;
}
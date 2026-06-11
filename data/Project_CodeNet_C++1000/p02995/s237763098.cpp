#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b){
  if(b==0) return a;
  else return GCD(b, a % b);
}
long long LCM(long long a, long long b) {
  long long g = GCD(a, b);
  return a / g * b;
}
int main() {
  long long A, B, C, D;
  cin >> A >> B >> C >> D;
  long long CD = LCM(C, D);
  cout << B - B/C - B/D + B/CD -(A-1) +(A-1)/C + (A-1)/D - (A-1)/CD << endl;
 
}
#include <bits/stdc++.h>
using namespace std;

long lcd(long a, long b) {
  long c = a * b / __gcd(a,b);
  return c;
}

int main() {
  long A,B,C,D; cin >> A >> B >> C >> D;
  long a = B / C;
  long b = B / D;
  long c = B / lcd(C,D);
  long d = (A - 1) / C;
  long e = (A - 1) / D;
  long f = (A - 1) / lcd(C,D);
  long divB = B - a - b + c; 
  long divA = A - 1 - d - e + f;
  long ans = divB - divA;
  cout << ans << endl;
}
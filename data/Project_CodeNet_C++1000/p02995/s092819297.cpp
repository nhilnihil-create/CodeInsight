#include <bits/stdc++.h>
using namespace std;
 
long GCD(long m, long n);

int main() {
  long A, B, C, D;
  cin >> A >> B >> C >> D;
  long Cmul_num = (B/C) - ((A-1)/C);
  long Dmul_num = (B/D) - ((A-1)/D);

  long LCM = C * D / GCD(C, D);
  long LCM_num = (B/LCM) - ((A-1)/LCM);

  long solution = B - A +1 - Cmul_num - Dmul_num + LCM_num;

  cout << solution << endl;
  return 0;
}

long GCD(long m, long n)
{
  if(m%n == 0) return n;
  else if(n%m == 0) return m;

  else if(m>n) return GCD(n, m%n);
  else return GCD(m, n%m);
}

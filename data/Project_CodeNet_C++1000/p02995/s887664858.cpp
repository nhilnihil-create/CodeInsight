#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b)
{
   if (a%b == 0)
   {
       return(b);
   }
   else
   {
       return(gcd(b, a%b));
   }
}

long long lcm(long long a, long long b)
{
   return a * b / gcd(a, b);
}
int main() {
  long long A, B, C, D;
  cin >> A >> B >> C >> D;

  long long countsToA = (A-1LL)/C + (A-1LL)/D - (A-1LL)/lcm(C,D);
  long long countsToB = B/C + B/D - B/lcm(C,D);
  
  cout << (B-A+1LL) - (countsToB-countsToA) << endl;

  return 0;
}
#include <bits/stdc++.h>
# define int long long
using namespace std;
int GCD(int a, int b)
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

int LCM(int a, int b)
{
   return a * b / GCD(a,b);
}



main() {
   int c,d;
   cin >> c >> d;
  int lcm = LCM(c,d);
  cout << lcm << endl;
  return 0;
}

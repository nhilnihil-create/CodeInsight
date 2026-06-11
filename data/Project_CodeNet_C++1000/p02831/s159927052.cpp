#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REPS(I, a, b) for (int i = (a); i < (b); ++i)
using namespace std;
using ll = long long;


int gcd(int a, int b)
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


int main() {
  ll a,b;
  cin >> a >> b;
  
  int c = gcd(a,b);
  
  ll ans = a/c * b/c * c;
  
  cout << ans << endl;
  
}

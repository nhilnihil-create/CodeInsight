#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define pow5(x) x*x*x*x*x

int main()
{
  long long x;
  cin >> x;
  
  int a, b = 0;
  int max_a = 200;
  
  bool signeture = (x > 0);
  x = abs(x);
  
  for(long long i = -max_a; i <= max_a; i++)
  {
    for(long long j = -max_a; j <= max_a; j++)
    {
      if(pow5(i) - pow5(j) == x)
      {
        a = i;
        b = j;
        break;
      }
    }
  }
  if(signeture) cout << a << " " << b << endl;
  else cout << b << " " << a << endl;
  return 0;
}
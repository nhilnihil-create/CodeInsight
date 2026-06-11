#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

using namespace std;

int main ()
{
  int N,b,res,power;
  vector<int> X;

  cin >> N;
  REPI(N)
  {
    cin >> b;
    X.push_back (b);
  }

  res = INT_MAX;
  REPI(101)
  {
    power = 0;
    REPJ(N)
    {
      power += pow(X[j]-i,2);
    }
    if (res > power)
      res = power;
  }

  cout << res << endl;
  
  return 0;
}
#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

using namespace std;

int main ()
{
  int A,B,res,port;

  cin >> A >> B;
  res = 1;
  port = A;

  if (B == 1)
  {
    cout << 0 << endl;
    return 0;
  }
  
  while (port < B)
  {
    res++;
    port += A - 1;
  }
  
  cout << res << endl;


  return 0;
}
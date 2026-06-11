#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

#define REPISE (s,e) for(int i=s,i<e;i++)
#define REPJSE (s,e) for(int j=s,j<e;j++)

typedef long long ll;

using namespace std;

int main ()
{
  long long H,W;
  cin >> H >> W;

  if (H == 1 || W == 1)
  {
    cout << 1 << endl;
    return 0;
  }
    

  if (H%2 == 0)
    cout << W * (H/2) << endl;
  else if (W%2 == 0)
    cout << H * (W/2) << endl;
  else
    cout << W * (H/2) + W/2 + 1 << endl;
  
  return 0;
}
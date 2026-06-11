#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t A, B;
  cin >> A >> B;
  
  int64_t H, L;
  int64_t C;
  int64_t r;
  
  if(A >= B)
  {
    H = A;
    L = B;
  }
  else
  {
    H = B;
    L = A;
  }
  r = H % L;
  while(r)
  {
    H = L;
    L = r;
    r = H % L;
  }
  cout << A * B / L << endl;
}
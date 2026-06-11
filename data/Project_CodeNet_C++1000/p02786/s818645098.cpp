#include<bits/stdc++.h>
using namespace std;
int main()
{
  int64_t H;
  cin >> H;
  int64_t A=0;
  int64_t B=1;
  int64_t C=1;
  if(H==1)
  {
    A=1;
  }
  
  while(A<1)
  {
    
    if(H==1)
  {
    break;
  }
    H=H/2;
    B=B+C*2;
    C=C*2;
  }
  cout << B << endl;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int X;
  int A=0;
  int B=0;
  cin >>X;
  while(1)
  {
   A=A-X;
   B++;
   if(A<0)A=A+360;
   if(A==0)break;
  }
  cout << B;
}
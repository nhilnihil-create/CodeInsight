#include <bits/stdc++.h>
using namespace std;

int main ()
{
  int A,B,C;
  cin>>A>>B;
  if(A!=0 && A<=3 && B!=0 && B<=3 && A!=B){
    cout << (6 - (A + B));
  }
  return 0;
}
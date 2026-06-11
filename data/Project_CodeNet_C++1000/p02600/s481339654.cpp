#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x,i,j,k,l;
  cin >> x;
  j=8;
  k=399;
  while(1)
  {
    k+=200;
    if(x<=k)
    {
      l=j;
      break;
    }
    j--;
  }
  cout << l << endl;
}
  
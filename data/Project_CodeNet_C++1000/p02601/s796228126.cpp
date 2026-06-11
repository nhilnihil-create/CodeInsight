#include<bits/stdc++.h>
using namespace std;
int main()
{
  int i,j,k,a,b,c;
  cin >> a >> b >> c;
  cin >> k;
  j=0;
  while(b<=a)
  {
  	b*=2;
    j++;
  }
  while(c<=b)
  {
    c*=2;
    j++;
  }
  if(j<=k)
  cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
  
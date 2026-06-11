#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,flag=0;
  cin >> a >> b;
  for(int i=1;i<1010;i++)
  {
    if((i*2)/25==a && i/10==b)
    {
      flag=1;
      cout << i;
      break;
    }
  }
  if(flag==0)
    cout<<"-1";
}
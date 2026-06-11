#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  bool f=false;
  for(int i=1;i<10;i++)
  {
    if(n%i==0)
    {
      if(n/i<10)
      {
        cout<<"Yes";
        f=true;
        break;
      }
    }
  }
  if(!f)
  cout<<"No";
}

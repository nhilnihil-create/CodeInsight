#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int co=0;
  for(int i=1;i<=n;i++)
  {

      int p;
      cin>>p;
      if(i&1)
      {
          if(p&1)
            co++;
      }
  }
  cout<<co<<endl;
}
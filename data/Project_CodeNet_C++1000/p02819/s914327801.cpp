#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,m;
  cin>>n;
  for(int i=n;;)
  {
      m=i/2;
      int flag=0;
      if(i==2)
      {
          cout<<i<<endl;
          break;
      }
      else
      {
          for(int j=2;j<=m;j++)
          {
              if(i%j==0)
              {
                  flag=1;
                  break;
              }

          }
          if(flag==0)
          {
              cout<<i<<endl;
              break;
          }
          else
          {
              i++;
          }
      }


  }
  return 0;




}

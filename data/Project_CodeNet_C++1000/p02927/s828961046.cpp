#include<bits/stdc++.h>
using namespace std;
int main()
{

  int a,b,c,r,d,l=0;
  cin>>a>>b;
  for(int i=1;i<=a;i++)
  {
      for(int j=1;j<=b;j++)
      {
          r=j%10;
          d=j/10;
          if(r>=2 && d>=2)
          {
          if(r*d==i)
          {
              l++;

          }
          }

      }

  }

cout<<l<<endl;
return 0;


}



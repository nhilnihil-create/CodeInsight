#include<bits/stdc++.h>
using namespace std;
int main()
  {
  int a,b,c,i,j=0;
  cin>>a;
  for(i=1;i<=a;i++)
  {cin>>b;
   if(i%2==1&&b%2==1)j++;
   }
  cout<<j<<endl;
  }
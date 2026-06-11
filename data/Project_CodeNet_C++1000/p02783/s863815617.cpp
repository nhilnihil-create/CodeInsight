#include<bits/stdc++.h>
using namespace std;
int main()
{
  int h,a,i;
  int cnt =0;
  cin>>h>>a;
  
  for(i=0;i<=h;i++)
  {
          i = a *cnt;
          cnt++;
  }
      cout<<"\n"<<cnt -1;
  return 0;
}

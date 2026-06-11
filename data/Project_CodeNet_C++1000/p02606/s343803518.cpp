#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,d,count=0;
  cin>>a>>b>>d;
  for(int i=a; i<=b; i++)
  {
    if(i%d==0)
      count++;
  }
  cout<<count;
  return 0;
}
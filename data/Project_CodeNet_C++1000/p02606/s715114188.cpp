#include<iostream>
using namespace std;
int main()
{
  int a,b,c;
  int res=0;
  cin>>a>>b>>c;
  for(;a<=b;a++)
    if(a%c==0)
      res++;
  cout<<res;
  return 0;
}
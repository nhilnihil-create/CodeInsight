#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  int p;
  if(b<a)
  {p=a-b;}
  if(p<c)
  {cout<<c-p;}
  else
    cout<<0;
  return 0;
}

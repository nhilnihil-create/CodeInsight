#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
  a=a-2*b;
  if(a<=0)
    cout<<0;
  else
    cout<<a;
}
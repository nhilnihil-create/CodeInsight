#include <bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c;
  cin>>a>>b>>c;
  if((a==b)&& (b== c) ||((a!= b) && (a!= c) && (b!=c)))
       cout<<"\nNo";
  else
    cout<<"Yes\n";
  return 0;
}
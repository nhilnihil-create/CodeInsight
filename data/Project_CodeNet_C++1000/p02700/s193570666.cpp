#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b,c,d;
  cin>>a>>b>>c>>d;
  int x=(a+d-1)/d;
  int y=(b+c-1)/b;
  if(x>=y)
  cout<<"Yes\n";
  else
  cout<<"No\n";
}

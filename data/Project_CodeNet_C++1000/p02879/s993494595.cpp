#include<bits/stdc++.h>
using namespace std;

bool ch(int a)
{
  if(a>0&&a<10)
    return true;
  return false;
}

int main()
{
  int a,b;
  cin>>a>>b;
  if(ch(a)&&ch(b))
    cout<<a*b;
  else
    cout<<"-1";
  
  return 0;
}

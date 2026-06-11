#include<bits/stdc++.h>
using namespace std;

int gcm(int x,int y)
{
  if(x%y==0)
    return y;
  return gcm(y,x%y);
}

int main()
{
  int64_t a,b;
  cin>>a>>b;
  cout<<a*b/gcm(a,b)<<endl;
}
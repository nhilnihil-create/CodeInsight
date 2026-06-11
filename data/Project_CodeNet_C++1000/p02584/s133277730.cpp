#include<bits/stdc++.h>
using namespace std;
int main()
{
long long x,k,d;
  cin>>x>>k>>d;
  x=abs(x);
long long sweep=min(k,x/d);
x-=sweep*d;
  k-=sweep;
  
  if(k%2==0)
    cout<<x<<endl;
  else
    cout<<d-x<<endl;
  
}
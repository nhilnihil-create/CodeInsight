#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
#define N 100010
void solve()
{
  int a,b,c,k;
  cin>>a>>b>>c>>k;
if(k<=a)
{
   cout<<k<<endl;
  return;
}
 else if(k<=a+b)
 {
    cout<<a<<endl;
    return;
 }
  else if(k<=a+b+c)
  {
    cout<<(k-a-b)*(-1)+a;
    return;
  }
    
}

int main()
{
    solve();
}

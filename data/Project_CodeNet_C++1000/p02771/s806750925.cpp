#include<bits/stdc++.h>>
using namespace std;
int main()
{
  int a,b,c,cnt=0;
  cin>>a>>b>>c;
if(a==b && b!=c)
    cnt=1;
if(b==c && c!=a)
     cnt=1;

if(c==a && a!=b)
     cnt=1;

  if(cnt==1)
    cout<<"Yes";
  else
    cout<<"No";


   return 0;
}





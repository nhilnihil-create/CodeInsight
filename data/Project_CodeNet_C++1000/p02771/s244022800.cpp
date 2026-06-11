#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,c;
  cin>>a>>b>>c;
  bool flag=false;
  if(a==b && c!=a)
    flag=true;
  if(a==c && b!=a)
    flag=true;
  if(b==c && a!=c)
    flag=true;
  if(flag)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  
  
  
}
#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long t,b,c,d,n,m,i,x,y;
  cin>>n;
  string s,a,aa;
  cin>>s;
  if(n%2){cout<<"No"<<endl;}
  else
  {
      x=n/2;
      for(i=0;i<x;i++)
      {
          a+=s[i];
      }
          for(i=x;i<n;i++)
      {
          aa+=s[i];
      }
      if(aa==a)cout<<"Yes"<<endl;
      else {cout<<"No"<<endl;}
  }

    return 0;
}

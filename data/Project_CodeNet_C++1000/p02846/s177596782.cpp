#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long t1,t2;cin>>t1>>t2;
  long long a1,a2;cin>>a1>>a2;
  long long b1,b2;cin>>b1>>b2;
  long long a1g=(a1-min(a1,b1))*t1;
  long long a2g=(a2-min(a2,b2))*t2;
  long long b1g=(b1-min(a1,b1))*t1;
  long long b2g=(b2-min(a2,b2))*t2;
  if(a1g==0&&a2g==0||b1g==0&&b2g==0)cout<<0<<endl;
  else
  {
    long long p1=a1g+b1g;
    long long p2=a2g+b2g;
    if(p1==p2)cout<<"infinity"<<endl;
    else if(p1>p2)cout<<0<<endl;
    else
    {
      long long p=p1/(p2-p1);
      long long ans=p*2+1;
      if(p1%(p2-p1)==0)ans--;
      cout<<ans<<endl;
    } 
  }
}

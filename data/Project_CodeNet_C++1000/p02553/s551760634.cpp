#include<bits/stdc++.h>
using namespace std;

int main()
{
 long long a,b,c,d;
  cin>>a>>b>>c>>d;
  long long ans,ans1,anss;
  ans=0;
  ans1=0;
  anss=0;
  ans=max(a*c,a*d);
 // cout<<a*c<<endl;
   ans1=max(b*c,b*d);
  anss=max(ans,ans1);
  cout<<anss<<endl;
  
}

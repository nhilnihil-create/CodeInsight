#include<bits/stdc++.h>
using namespace std;
int main()
{
  double d,t,s;
  cin>>d>>t>>s;
  double x=(d*0.1)/(s*0.1);
  if(x<=t)
    cout<<"Yes";
  else
    cout<<"No";
}
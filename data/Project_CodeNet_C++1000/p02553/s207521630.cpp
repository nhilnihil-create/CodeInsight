#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{	
  ll a,b,c,d,e,f;
  
  cin>>a>>b>>c>>d;
  
  e=max(a*c,a*d);
  f=max(b*c,b*d);
 
  cout<<max(e,f);
  
  return 0;
}
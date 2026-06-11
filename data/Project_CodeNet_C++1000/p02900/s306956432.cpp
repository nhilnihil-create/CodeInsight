#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long a,b;
  cin>>a>>b;
  set<long long>ans;
  long long A=a;
  long long B=b;
  long long g=__gcd(a,b);
  for(int i=2;(long long)i*i<=g;i++)
  {
	long long t=i;
    if(g%t==0)
    {
      ans.insert(t);
      while(g%t==0)g/=t;
    }
  }
  if(g>1)ans.insert(g);
  cout<<ans.size()+1<<endl;
  return 0;
 }
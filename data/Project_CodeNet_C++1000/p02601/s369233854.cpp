#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b,c,k;
  cin>>a>>b>>c>>k;
  int need=0;
  while(a>=b)
  {
    b*=2;
    need++;
  }
  while(b>=c)
  {
	  c*=2;
	  need++;
  }
  if(need<=k)
  {
	  cout<<"Yes\n";
  }
  else
  {
	  cout<<"No\n";
  }
}

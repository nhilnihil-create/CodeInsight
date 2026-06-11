#include<iostream>
using namespace std;
main()
{
	int p,q,r,m,n,t;
	cin>>p>>q>>r;
    m=min(p,q);
    n=min(q,r);
    t=min(p,r);
    if(m==t)
    {
      cout<<m+n<<"\n";
    }
  else if(m==n)
  {
    cout<<m+t<<"\n";
  }
  else if(n==t)
  {
    cout<<n+m<<"\n";
  }
}
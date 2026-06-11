#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
  int n,i;cin>>n;
  static double x[100],a,y,p,q,r,s;

  for(i=0;i<n;i++)cin>>x[i];
  for(i=0;i<n;i++)cin>>y,p+=a=abs(x[i]-y),q+=a*a,r+=a*a*a,s=s<a?a:s;
  cout<<fixed<<p<<endl<<sqrt(q)<<endl<<cbrt(r)<<endl<<s<<endl;
  return 0;
}
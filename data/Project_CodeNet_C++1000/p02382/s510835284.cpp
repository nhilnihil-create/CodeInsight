#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
  int n,i;cin>>n;
  static double x[100],a[100],y,p1,p2,p3,p4;

  for(i=0;i<n;i++)cin>>x[i];
  for(i=0;i<n;i++)cin>>y,a[i]=abs(x[i]-y),p1+=a[i],p2+=a[i]*a[i],p3+=a[i]*a[i]*a[i],p4=p4<a[i]?a[i]:p4;
  cout<<fixed<<p1<<endl<<sqrt(p2)<<endl<<cbrt(p3)<<endl<<p4<<endl;
  return 0;
}
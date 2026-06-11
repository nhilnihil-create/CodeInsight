#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int x[n];
  int y[n];
  int a[n];
  for(int i=0;i<n;i++)
    cin>>x[i];
  for(int i=0;i<n;i++)
  {
    cin>>y[i];
    a[i]=abs(x[i]-y[i]);
  }

  double d1=0,d2=0,d3=0,di=0;
  for(int i=0;i<n;i++)
    d1+=a[i];
  for(int i=0;i<n;i++)
    d2+=a[i]*a[i];
  d2=sqrt(d2);
  for(int i=0;i<n;i++)
    d3+=a[i]*a[i]*a[i];
  d3=pow(d3,1.0/3);
  for(int i=0;i<n;i++)
    if(di<a[i]) di=a[i];

  cout<<fixed<<d1<<endl<<d2<<endl<<d3<<endl<<di<<endl;
}
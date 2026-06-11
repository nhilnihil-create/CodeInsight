#include<iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
  int n;
  int x[100];
  int y[100];
  int i;
  long double p1=0.0;
  long double p2=0.0;
  long double p3=0.0;
  long double p=0.0;
  int max=0;
  
  cin >>n;
  
  for(i=0;i<n;i++)
    cin >>x[i];
  for(i=0;i<n;i++)
    cin >>y[i];
  
  for(i=0;i<n;i++)
    p1=p1+abs(x[i]-y[i]);
  
  for(i=0;i<n;i++)
  {
    p2+=abs(x[i]-y[i])*abs(x[i]-y[i]);
  }
  p2=sqrt(p2);
  
  for(i=0;i<n;i++)
  {
    p3+=abs(x[i]-y[i])*abs(x[i]-y[i])*abs(x[i]-y[i]);
  }
  p3=pow(p3, 1.0/3.0);
  
  for(i=0;i<n;i++)
  {
    if(abs(x[i]-y[i])>max)
      max=abs(x[i]-y[i]);
  }
  p=max;
  
  cout << fixed << setprecision(6) << p1 << "\n";
  cout << fixed << setprecision(6) << p2 << "\n";
  cout << fixed << setprecision(6) << p3 << "\n";
  cout << fixed << setprecision(6) << p << "\n";
  
}
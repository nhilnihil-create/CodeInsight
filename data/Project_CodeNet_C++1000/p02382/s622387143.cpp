#include <iostream>
#include <cmath>
using namespace std;

double power(double x,int n)
{
  double y=1;
  for(int i=0;i<n;i++)
    y*=x;
  return y;
}

int main()
{
  int n;
  int x[100],y[100];
  int p;
  unsigned long long sum;
  cin >> n;
  for(int i=0;i<n;i++)
    cin >> x[i];
  for(int i=0;i<n;i++)
    cin >> y[i];

  for(p=1;p<=3;p++)
    {
      sum=0.0;
      for(int i=0;i<n;i++)
	sum+=power((x[i]-y[i]<0)?(y[i]-x[i]):(x[i]-y[i]),p);
    
      cout.precision(10);
      cout.setf(ios::fixed);
      cout << pow(sum,1.0/p) << endl;
    }

  sum=0.0;
 
  
    
 
  int max=0.0;
  for(int i=0;i<n;i++)
    {
      sum=(x[i]-y[i]<0)?(y[i]-x[i]):(x[i]-y[i]);
      if(sum>max)
	max=sum;
    }
  cout.precision(10);
  cout.setf(ios::fixed);
  cout << max << endl;

  return 0;
}
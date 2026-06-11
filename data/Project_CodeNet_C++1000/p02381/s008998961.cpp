#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
  int n;
  int s[1000];
  long double sum;
  long double m;
  long double a;
  int i;
  
  while(1)
  {
    cin >> n;
    if(n==0)
      break;
      
    for(i=1;i<=n;i++)
    {
      cin >> s[i];
      sum+=s[i];
    }
    
    m=sum/n;
    
    
    for(i=1;i<=n;i++)
    {
      a+=(s[i]-m)*(s[i]-m);
    }
    
    a=sqrt(a/n);
    cout << fixed << setprecision(6) << a << "\n";
    
    sum=0;
    a=0;
  }
}
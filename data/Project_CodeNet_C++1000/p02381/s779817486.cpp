#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
  int n;

  while(1)
    {
      double a2=0, m=0;
      cin >> n;
      if(n==0)
	break;
      double s[n];
      for(int i=0;i<n;i++)
	cin >> s[i];
      for(int i=0;i<n;i++)
	m += s[i];
      m /= n;
      for(int i=0;i<n;i++)
	a2 += (s[i]-m)*(s[i]-m);
      a2 /= n;
      cout << fixed << setprecision(5)
	   << sqrt(a2) << endl;
    }
}
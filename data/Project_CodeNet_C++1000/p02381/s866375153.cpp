#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
  int n;
  int s[1000];
  
  while ( cin >> n && n != 0 )
    {
      double a = 0, m = 0;
      
      for ( int i = 0; i < n; i++ )
        {
          cin >> s[i];
          m += s[i];
        }
      
      m /= n;

      for ( int i = 0; i < n; i++ )
        {
          a += (s[i] - m) * (s[i] - m);
        }
      
      cout << fixed << setprecision(6) << sqrt( a / n ) << endl;
    }
    
  return 0;
}
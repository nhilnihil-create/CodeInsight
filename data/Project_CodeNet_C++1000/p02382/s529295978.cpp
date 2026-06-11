#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main()
{
  int n, x[100], y[100];
  double d1 = 0, d2 = 0, d3 = 0, d8 = 0;

  cin >> n;

  for ( int i = 0; i < n; i++ )
    {
      cin >> x[i];
    }
  
  for ( int i = 0; i < n; i++ )
    {
      cin >> y[i];
    }

  for ( int i = 0; i < n; i++ )
    {
      double d = abs( x[i] - y[i] );
      d1 += d;
      d2 += d * d;
      d3 += d * d * d;
      d8 = max( d8, d );
    }

  d2 = sqrt( d2 );
  d3 = pow( d3, 1.0/3.0 );
  
  cout << fixed << setprecision(6) << d1 << endl;
  cout << fixed << setprecision(6) << d2 << endl;
  cout << fixed << setprecision(6) << d3 << endl;
  cout << fixed << setprecision(6) << d8 << endl;
  
  return 0;
}
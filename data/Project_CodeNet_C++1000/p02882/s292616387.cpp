#include<bits/stdc++.h>
using namespace std;

int main()
{
  long double a,b,x;cin>>a>>b>>x;
  if (a*a*b/2.0 <= x)
  cout << fixed << setprecision(10) << atanl(2.0/a* (b- x/a/a)) * 180 / acos(-1) << endl;
  else
  cout << fixed << setprecision(10) << (acos(-1)/2 - atanl(2*x/a/b/b))* 180 / acos(-1) << endl;
}
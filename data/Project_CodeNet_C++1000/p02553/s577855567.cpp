
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int main()
{  
 
 ll a, b , c ,d;
 cin >> a >> b >> c >> d;

 ll max = a * c;

 ll r1 = b*c;
 ll r2 = a*d;
 ll r3 = b*d;

  if (max<r1)max=r1;
  if (max<r2)max=r2;
  if (max<r3)max=r3;
   
  cout << max;

 return 0;
}




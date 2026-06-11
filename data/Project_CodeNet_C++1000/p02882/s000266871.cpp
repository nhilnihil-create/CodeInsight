#include <bits/stdc++.h>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ll long long
using namespace std;

int main() {
  long double pi = 3.1415926535;
  long double a, b, x;
  cin >> a >> b >> x;
  long double thita;
  
//  cout << x << " " << a*a*b << endl;
  
  if(2*x < a*a*b) {
  	long double y = (2*x) / (a*b);
	thita = pi/2 - atan(y/b);
  } else {
    long double anotherx = a*a*b - x;
    long double y = (2*anotherx) / (a*a);
    thita = atan(y/a);
  }
  
  cout << fixed << 180*thita/pi << endl; 
      
  return 0;
}

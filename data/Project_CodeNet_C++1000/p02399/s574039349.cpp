#include <bits/stdc++.h>
using namespace std;

int a,b;
int d,r;
double f;

int main() {
  cin >> a >> b;
  d = a / b;
  r = a % b;
  f = (1.0*double(a))/double(b);
  cout << d << " " << r << " " << fixed << setprecision(5) << f << endl;

  return 0;
  
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
#define ll long long
using namespace std;



int main() {
  double PI = 3.14159265358979;
  int a, b, h, m;
  cin >> a >> b >> h >> m;
  double degree = abs((h*30.0+m/2.0)-m*6.0);
  
  double dist = sqrt(a*a + b*b - 2.0*a*b*cos((degree/180)*PI));
  cout << fixed << setprecision(15);
  cout << dist << endl;
  return 0;
}

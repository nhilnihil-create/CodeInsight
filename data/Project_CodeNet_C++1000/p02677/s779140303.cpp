#include <bits/stdc++.h>
#define PI 3.14159265358979323846264338327950L
using namespace std;
int main(){
  long double a,b,h,m; cin >> a >> b >> h >> m;
  long double rad = (h/12 + (m /60)/12 - m/60) * 2 * PI;
  long double c = a * a + b * b - 2 * a * b * cos(rad);
  printf("%.20Lf\n",sqrt(c));
}
#include<cstdio>
#include<iostream>
#include<cctype>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define ll long long
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define MD 1000000007

char sep[3] = " \n";
int i, j, k, l, m, n;
double PI = acos(-1);


int main() {
  double a, b, c;
  cin >> a >> b >> c;
  c = PI*c/180;
  printf("%.5f\n%.5f\n%.5f\n",
         0.5 * a * b * sin(c),
         a + b + sqrt(a*a + b*b - 2.0*a*b*cos(c)),
         b * sin(c));

  return 0;
}
  
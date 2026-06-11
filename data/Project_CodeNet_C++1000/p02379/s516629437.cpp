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
  double x1, y1, x2, y2, dx, dy;
  cin >> x1 >> y1 >> x2 >> y2;
  dx = x2 - x1, dy = y2 - y1;
  printf("%.5f\n", sqrt(dx*dx+dy*dy));

  return 0;
}
  
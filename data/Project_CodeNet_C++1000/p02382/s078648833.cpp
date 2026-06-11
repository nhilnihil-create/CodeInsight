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
  double x[110], y[110], d[110];
  cin >> n;
  rep(i,n) cin >> x[i];
  rep(i,n) cin >> y[i];
  rep(i,n) d[i] = fabs(x[i] - y[i]);
  // p = 0
  double z = 0.0;
  rep(i,n) z+=d[i];
  printf("%.6f\n", z);
  // p = 1
  z = 0.0;
  rep(i,n) z+=d[i]*d[i];
  printf("%.6f\n", sqrt(z));
  // p = 2
  z = 0.0;
  rep(i,n) z+=d[i]*d[i]*d[i];
  printf("%.6f\n", pow(z, 1.0/3.0));
  // p = inf
  z = 0.0;
  rep(i,n) if (d[i]>z) z=d[i];
  printf("%.6f\n", z);
  
  return 0;
}
  
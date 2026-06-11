#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int n;
  double m=0, u=0, t=0, c=0;
  cin >> n;

  int a[n], b[n];
  for(int i=0; i<n; i++) cin >> a[i];
  for(int i=0; i<n; i++) cin >> b[i];

  for(int i=0; i<n; i++){
    m+=abs(a[i]-b[i]);
    u+=pow(a[i]-b[i], 2);
    t+=pow(abs(a[i]-b[i]),3);
    c=max(c, (double)abs(a[i]-b[i]));
  }

  printf("%lf\n%lf\n%lf\n%lf\n", m, sqrt(u), cbrt(t), c);

  return 0;
}


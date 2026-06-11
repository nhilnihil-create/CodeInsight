#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int m = (n+1)/2;
  double ans = (double)m / (double)n;
  printf("%.10lf\n", ans);
}
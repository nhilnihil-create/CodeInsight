#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  double x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  double ans = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  printf("%0.8f\n", ans);
  return 0;
}
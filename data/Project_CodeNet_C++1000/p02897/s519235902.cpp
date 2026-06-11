#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  double n;
  cin >> n;
  double cnt = 0.0;
  for(int i = 1; i <= n; i++) {
    if(i % 2 != 0) cnt++;
  }
  
  double ans = cnt / n;
  printf("%.7f\n", ans);
}
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  double ans = 0.0;
  cin >> n;
  
  rep(i, n) {
    int a;
    cin >> a;
    ans += 1.0/a;
  }
  ans = 1.0/ans;
  printf("%.16f\n", ans);
}
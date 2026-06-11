#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
constexpr double EPS = 1e-8; 

int main(){
  int64 a;
  double b;
  cin >> a >> b;
  int64 bb = b * 100.0 + EPS;
  int64 ans = a * bb / 100LL;
  cout << ans << endl;
}
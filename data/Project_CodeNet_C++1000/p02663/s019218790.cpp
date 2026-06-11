#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c,d,e;
  cin >> a >> b >> c >> d >> e;
  int s=a*60+b;
  int t=c*60+d;
  cout << t-e-s << '\n';
  return 0;
}
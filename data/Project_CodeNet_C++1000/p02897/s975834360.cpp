#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int a = n/2+1;
  double b = n;
  double ans;

  if (n%2==0)
  ans = 1./2.;
  else
  ans = a/b;
  
  cout << ans << endl;
}
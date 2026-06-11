#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x, t;
  cin >> n >> x >> t;
  int res = (n+x-1)/x * t;
  cout << res << endl;
  return 0;
}
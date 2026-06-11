#include <bits/stdc++.h>
using namespace std;

int main(){
  int k, a, b;
  cin >> k >> a >> b;
  int n = (b / k) * k;
  if (a <= n) puts("OK");
  else puts("NG");
  return 0;
}

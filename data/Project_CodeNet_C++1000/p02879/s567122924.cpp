#include <bits/stdc++.h>
using namespace std;

int main(void){
  int a, b, ans;
  cin >> a >> b;
  if(a < 10 && b < 10) ans=a*b;
  else ans = -1;
  cout << ans <<endl;
  return 0;
}
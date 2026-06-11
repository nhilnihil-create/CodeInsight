#include <bits/stdc++.h>
using namespace std;

int main(void){
  int a, b, ans;
  cin >> a >> b;
  if(a >= 2*b) ans=a-2*b;
  else ans = 0;
  cout << ans <<endl;
  return 0;
}
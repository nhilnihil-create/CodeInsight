#include<bits/stdc++.h>
using namespace std;

int main(void){
  int a, ans = 0, cp = 1;
  cin >> a;
  for(int i = 0; i < 3; i++){
    cp *= a;
    ans += cp;
  }
  cout << ans << endl;
  return 0;
}
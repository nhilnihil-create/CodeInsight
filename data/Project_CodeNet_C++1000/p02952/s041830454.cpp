#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int ans=0;
  
  if(n>=10){
    if(n>=1000){
      if(n>=10000 && n!=100000){
        ans += n-9999;
        ans += 909;
      } else if(n==100000){
        ans = 90909;
      } else {
        ans += 909;
      }
    } else if(n>=100){
      ans += n-99;
      ans += 9;
    } else {
      ans = 9;
    }
  } else {
    ans = n;
  }
  
  cout << ans << endl;
  
}

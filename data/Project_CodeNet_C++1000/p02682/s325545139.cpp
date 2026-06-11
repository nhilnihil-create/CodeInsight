#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int64_t a,b,c,k,ans;
  cin >> a >> b >> c >> k;
  if(k <= a){
    ans = 1*k;
  }else if(k <= a+b){
    ans = 1*a;
  }else{
    ans = 1*a - (k-a-b)*1;
  }
  cout << ans << endl;
}
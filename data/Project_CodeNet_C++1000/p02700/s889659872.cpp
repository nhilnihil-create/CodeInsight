#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d;
  string ans;
  cin >> a >> b >> c >> d;
  while(1){
    c = c - b;
    if(c<=0){
      ans = "Yes";
      break;
    }
    a = a - d; 
    if(a<=0){
      ans ="No";
      break;
    }
  }
  cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int k;
  cin >> k;
  if(a>=b){
    while(k--){
      b*=2;
      if(a<b)break;
    }
  } 
  if(b>=c){
    while(k--){
      c*=2;
      if(c>b)break;
    }
  }  
  
  if(c>b&&b>a)cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
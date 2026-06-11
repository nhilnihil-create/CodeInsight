#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
 int a,b;
 cin >> a >> b;
 
 int x = 0;
 
 for(int i = 1; i < 1009; i++) {
 if(i * 8/100  == a && i * 10/100 == b) {
  x = i;
  break;
  }
   }
   
   if(x != 0) {
    cout << x;
    }
    else {
     cout << -1;
     }
  
  
}
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
   int a,b;
    cin >> a >> b;
    
    bool x = false;
  int ans = 0;
    
    rep(i,1005) {
     int za = i*8/100;
     int zb = i*10/100;
     
        if(a == za && b == zb){
           x = true;
           ans = i;
            break;
        }
        
     }
    if(x) {
        cout << ans;
          }
    else {
    cout << -1;
    }
    
}

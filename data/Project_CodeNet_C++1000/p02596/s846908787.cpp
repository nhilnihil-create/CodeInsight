//BISMILLAH
#include <bits/stdc++.h>
using namespace std;
int main(){
    
     int i,j,k,ans = 0;
     cin >> k;
     for(i = 1;i<=1e7;i++){
         ans = ((ans * 10) + 7) % k;
         if(ans == 0) {
             cout << i << endl;
             return 0;
         }
     }
      cout << -1 << endl;
    return 0;
}
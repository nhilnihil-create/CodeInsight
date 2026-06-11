#include <iostream>
#include <algorithm>

using namespace std;

int n, ans;

main(){
   cin >> n;
   for(int i=0;i<n;i++){
      int y, m, d;
      cin >> y >> m >> d;
      ans = 0;
      for(int j=y+1;j<1000;j++){
         if(j%3){
            ans += 195;
         }else{
            ans += 200;
         }
      }

      for(int j=m+1;j<=10;j++){
         if(y%3){
            if(j%2) ans += 20;
            else ans += 19;
         }else{
            ans += 20;
         }
      }
      if(y%3){
         if(m%2){
            ans += 20-d;
         }else{
            ans += 19-d;
         }
      }else{
         ans += 20-d;
      }
      cout << ans+1 << endl;
   }
}
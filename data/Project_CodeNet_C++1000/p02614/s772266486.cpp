#include <iostream>
#include <string>

using namespace std;

int main(){

   int h, w, k;
   string c[6];
   int ans = 0;

   cin >> h >> w >> k;

   for(int i = 0; i < h; i++){
      cin >> c[i];
   }

   int num = 0;
   // for(int i = 0; i < h; i++){
   //    for(int j = 0; j < w; j++){
   //       if(c[i][j] == "#"){
   //          num++;
   //       }
   //    }
   // }

   // if(num == k){
   //    ans++;
   // }

   for(int i = 0; i < (1 << h); i++){
      for(int j = 0; j < (1 << w); j++){
         
         num = 0;
         for(int ii = 0; ii < h; ii++){
            if(i & (1 << ii)){
               continue;
            }
            for(int jj = 0; jj < w; jj++){
               if(!(j & (1 << jj))){
                  if(c[ii][jj] == '#'){
                     num++;
                  }
               }
            }
         }

         if(num == k){
            ans++;
            // cout << i << " " << j << endl;
         }

      }
   }

   cout << ans << endl;

   return 0;
}
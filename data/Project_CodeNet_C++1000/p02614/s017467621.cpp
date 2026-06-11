#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int h,w,k;
   cin >> h >> w >> k;
   char c[h][w];
   rep(i,h){
      rep(j,w){
         cin >> c[i][j];
      }
   }
   int ans=0;
   rep(maskR,1<<h){
      rep(maskC,1<<w){
         int black=0;
         rep(i,h){
            rep(j,w){
               if(((maskR>>i) & 1)==0 && ((maskC>>j) & 1)==0 
            && c[i][j]=='#'){
               black++;
            }
            }
         }
         if(black==k){
            ans++;
         }
      }
   }

   cout << ans << endl;
   return 0;  
}
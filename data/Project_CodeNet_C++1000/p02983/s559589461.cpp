#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

 int main() {
   int l, r; cin>>l>>r;
   int ans=2019;
   // 選ばれた2つの整数i,jの余り同士の掛け算でよい
   // lとrの差が2019以上あるなら、答えは0
   if(r-l>=2019) {
     ans = 0;
   } else {
     for(int i=l; i<=r-1; i++) {
       for(int j=i+1; j<=r; j++) {
         int iMod = i%2019, jMod = j%2019;
         ans=min(ans,(iMod*jMod)%2019);
       }
     }
   }
   cout << ans << endl;
 }

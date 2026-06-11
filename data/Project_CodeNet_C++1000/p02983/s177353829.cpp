#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
 ll l,r;  ll ans=2019;
 cin >> l >> r;
 if(r-l>=673){
   cout << 0 << endl;
   return 0;
 }
 else{
   for(ll i=l;i<=r;i++){
     for(ll j=l+1;j<=r;j++){
       if(i>=j)continue;
       ll d=(i*j)%2019;
       ans=min(d,ans);
     }
   }
   cout << ans << endl;
 }

}

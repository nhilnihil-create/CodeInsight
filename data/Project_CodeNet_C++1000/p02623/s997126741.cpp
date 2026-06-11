#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n,m,k;
   cin >> n >> m >> k;
   vector<ll> a(n+1),b(m+1);
   ll A=0,B=0;
   a[0] = 0;
   b[0] = 0;
   rep(i,n){
      ll s;
      cin >> s;
      A += s;
      a[i+1] = A;
   } 
   rep(i,m){
      ll s;
      cin >> s;
      B += s;
      b[i+1] = B;
   } 
   ll ans=0;
   int j=m;
   rep(i,n+1){
      if(a[i]>k) break;
      while(a[i]+b[j]>k && j>0){
         j--;
      }

      ans = max(ans,(ll)(i+j));
   }

   cout << ans << endl;
   return 0;  
}
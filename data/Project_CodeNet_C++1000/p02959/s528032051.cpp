#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
//二項係数の計算
int nCr(ll A, ll B) {
    ll ans = 1;
    for (ll i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (ll i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
   ll N;
   cin>>N;
   vector<ll>A(N+1);
   vector<ll>B(N);
   rep(i,N+1){
       cin>>A[i];
   }
   ll ans=0;
   ll k=0;
   rep(i,N){
       cin>>B[i];
       bool a=true;
       while(a==true){
           if(k-i==2){
               a=false;
           }
           else{
       if(A[k]<=B[i]){
           ans+=A[k];
           B[i]-=A[k];
           k++;
       }
       else{
           A[k]-=B[i];
           ans+=B[i];
         if(k==i){
           k++;
         }
           a=false;
       }
       }
       }
   }
  cout<<ans<<endl;
}

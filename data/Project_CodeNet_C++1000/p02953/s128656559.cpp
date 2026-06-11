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
   int N;
   cin>>N;
   vector<int>H(N);
   bool a=true;
   rep(i,N){
       cin>>H[i];
       if(i==0){
           H[i]--;
       }
       else{
           if(H[i]<H[i-1]){
               a=false;
               break;
           }
           else if(H[i]==H[i-1]){

           }
           else
           {
               H[i]--;
           }
           
       }
   }
   if(a==true){
       cout<<"Yes"<<endl;
   }
   else
   {
       cout<<"No"<<endl;
   }
   
}

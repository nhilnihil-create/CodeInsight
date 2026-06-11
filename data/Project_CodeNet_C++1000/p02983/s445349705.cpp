#include <bits/stdc++.h>
using namespace std;


#define fast_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
using lli = long long int;
using ll = long long ;
using ld=long double;
using d= double;

bool isPrime(ll n){if(n<2)return false;for(ll i=2;i*i<=n;++i){if(n%i==0){return false;}}return true;}

ll lcm(ll x,ll y){
    return (x*y)/(__gcd(x,y));
}

signed main(){
    fast_IO;
    int t=1;
    //cin>>t;
    while(t--){
         ll l,r;
         cin>>l>>r;
         int ans=100000;
         for(ll i=l;i<r;i++){
             for(ll j=i+1;j<=r;j++){
                 if((i%2019)*(j%2019)%2019==0){
                     cout<<0;
                     return 0;
                 }
                 else if((i%2019)*(j%2019)%2019<ans){
                     ans=(i%2019)*(j%2019)%2019;
                 }
             }
         }
         cout<<ans;
    }   
    return 0;
}

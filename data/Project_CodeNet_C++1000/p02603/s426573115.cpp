#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

int main() {
    ll n;
    ll mo=1000;
    ll kb=0;
    ll ans=1000;
   
    cin>>n;
    vll a(n);
    rep(i,n) cin>>a[i];
    rep(i,n){
        ll ansi;
        if(i!=n-1){
           if(a[i]>a[i+1]){
              mo+=kb*a[i];
              ansi=mo;
              kb=0;
              kb=mo/a[i+1];
              mo-=kb*a[i+1];
           }
           else{
               int x=mo/a[i];
               kb+=x;
               mo-=a[i]*x;
               mo+=kb*a[i+1];
               ansi=mo;
               kb=0;
               
           }
           
        }
        ans=max(ans,ansi);
    }
    cout<<ans<<endl;
  

}

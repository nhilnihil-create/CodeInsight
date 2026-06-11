 #include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<int,int>;

ll f(ll x,ll c,ll d){
    ll res =x;
    res -=x/c;
    res -=x/d;
    res+= x/lcm(c,d);
    return res;
}

int main(){
   ll h,w,k;
   cin>>h>>w>>k;
   vector<string>s(h);
   rep(i,h){
       cin>>s[i];
   }
   ll ans=0;
   for(ll i=0;i<(1<<h);i++){
       for(ll j=0;j<(1<<w);j++){
           ll cnt=0;
           for(ll is=0;is<h;is++){
               for(ll js=0;js<w;js++){
                   if(i>>is&1)continue;
                   if(j>>js&1)continue;
                   if(s[is][js]=='#')cnt++;
               }
           }
           if(cnt==k)ans++;
       }
   }
   cout<<ans<<endl;
}

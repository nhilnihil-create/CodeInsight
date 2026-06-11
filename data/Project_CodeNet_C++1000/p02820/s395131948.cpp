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
   ll n,k;
   cin>>n>>k;
   vector<ll>v(3);
   rep(i,3)cin>>v[i];
   ll sum=0;
   string a;
   cin>>a;
   rep(i,n){
       if(a[i]=='s')sum+=v[0];
       if(a[i]=='p')sum+=v[1];
       if(a[i]=='r')sum+=v[2];
   }
   rep(i,k){
     bool ok=true;
     ll j=i+k;
     while(j<n){
         if(a[j]==a[j-k]){
             if(ok){
                   if(a[j]=='s')sum-=v[0];
                   if(a[j]=='p')sum-=v[1];
                   if(a[j]=='r')sum-=v[2];
                   j+=k;
                   ok=false;
                   continue;
             }
         }
         ok=true;
         j+=k;
     }
   }
cout<<sum<<endl;
}

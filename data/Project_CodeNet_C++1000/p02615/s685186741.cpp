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
   ll n;
   cin>>n;
   vector<ll>v(n);
   rep(i,n){
       cin>>v[i];
   }
   sort(v.rbegin(),v.rend());
   ll sum=0;
   ll a=0;
   ll tmp=0;
   rep(i,n-1){
       sum+=v[a];
       if(a==0)a++;
       else{
           tmp++;
       }
       if(tmp==2){
           a++;
           tmp=0;
       }
   }
   cout<<sum<<endl;
}

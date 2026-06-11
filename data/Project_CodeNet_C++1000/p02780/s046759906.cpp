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
   double sum=0;
   vector<ll>v(n);
   rep(i,n)cin>>v[i];
   vector<double>s(n);
   rep(i,n){
       double a=((1+v[i])/2.0);
       s[i]=a;
   }
   sum=0;
   rep(i,k)sum+=s[i];
   double ans=sum;
   rep(i,n-k){
       sum-=s[i];
       sum+=s[i+k];
       ans=max(ans,sum);
   }
          cout<<fixed<<setprecision(10)<<ans<<endl;
}

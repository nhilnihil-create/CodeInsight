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
  ll x;
  cin>>x;
  Rep(i,10000){
      for(ll j=-10000;j<10000;j++){
               if(pow(i,5)-pow(j,5)==x){
                   cout<<i<<" "<<j<<endl;
                   return 0;
               }
      }
     
      
  }
}

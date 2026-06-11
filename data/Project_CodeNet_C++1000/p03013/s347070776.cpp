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
    ll n,m;
    cin>>n>>m;
    vector<ll>v(n+1,-1);
    v[0]=1;
    v[1]=1;
    ll a;
    rep(i,m){
       cin>>a;
       v[a]=0;
    }
    for(ll i=2;i<n+1;i++){
        if(v[i]!=0){
        v[i]=(v[i-1]+v[i-2])%1000000007;
        }
    }
    cout<<v[n]%1000000007<<endl;
}

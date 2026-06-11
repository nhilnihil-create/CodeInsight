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
    vector<ll> v(n),s(n);
    rep(i,n){
        cin>>v[i];
    }
    rep(i,m){
        ll a,b;
        cin>>a>>b;
        a--;b--;
        if(v[a]==v[b]){
            s[a]=-1;
            s[b]=-1;
        }
        if(v[a]<v[b])s[a]=-1;
        if(v[b]<v[a])s[b]=-1;
    }
    ll ans=0;
    rep(i,n){
        if(s[i]==0)ans++;
    }
    cout<<ans<<endl;
}

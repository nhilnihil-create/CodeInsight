#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#define ll long long
#define INF 100000000000
#define N 10000000
using namespace std;


int main(void){
    ll n,m;
    ll k;
    cin>>n>>m>>k;
    ll a[n+1],b[m+1];
    
    a[0]=0;
    for (ll i=1; i<=n; i++){
        ll p;
        cin>>p;
        a[i]=a[i-1]+p;
    }
    
    b[0]=0;
    for (ll i=1; i<=m; i++){
        ll p;
        cin>>p;
        b[i]=b[i-1]+p;
    }
    
    vector<ll> bb;
    for (ll i=0; i<=m; i++){
        bb.push_back(b[i]);
    }
    
    ll ans=0;
    for(ll i=0; i<=n; i++){
        if (k<a[i]) break;
        ll x=k-a[i];
        
        auto it=upper_bound(bb.begin(),bb.end(),x);
        ll index=it-bb.begin()-1;
        
        if(x<b[1]) index=0;
        if(x>=b[m]) index=m;
        
        if (ans<index+i) ans=index+i;
        
        //cout<<x<<" "<<b[m]<<" "<<index<<endl;
    }
    
    cout<<ans<<endl;
    
}

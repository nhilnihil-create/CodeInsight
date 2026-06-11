#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 200000
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    priority_queue<ll> num;
    vector<ll> data[N];
    
    for (ll i=0; i<n; i++){
        ll p,q;
        cin>>p>>q;
        data[p].push_back(q);
    }
    
    ll ans=0;
    
    for (ll day=1; day<=m; day++){
        for (ll x:data[day]) num.push(x);
        if (!num.empty()){
            ans+=num.top();
            num.pop();
        }
        else continue;
    }
    
    cout<<ans<<endl;
}
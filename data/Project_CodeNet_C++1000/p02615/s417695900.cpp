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

int main(){
    ll n;
    cin>>n;
    vector<ll> data;
    for(ll i=0; i<n; i++){
        ll p;
        cin>>p;
        data.push_back(p);
    }
    
    sort(data.begin(),data.end());
    ll ans=data[n-1];
    ll p=n-2;
    
    for(ll i=1; i<n-1; i++){
        ans+=data[p];
        if(i%2==0) p--;
    }
    
    cout<<ans<<endl;
}
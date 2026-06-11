#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <queue>
#include <math.h>
#include <bitset>
#define INF 100000000000
#define N 1000000007
#define ll long long
using namespace std;

int main(){
    ll n; cin>>n;
    
    ll ans=1;
    map<ll,int> mp;
    
    for(ll i=0; i<n; i++){
        ll p; cin>>p;
        if(p==0) ans*=3-mp[0];
        else ans*=mp[p-1]-mp[p];
        mp[p]++;
        ans%=N;
    }
    
    cout<<ans<<endl;
}
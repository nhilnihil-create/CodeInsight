#include <bits/stdc++.h>
using namespace std;
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <math.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using pint = pair<int,int>;
using vec = vector<int>;
using ll=long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;



int main() {
    ll mod=2019;
    ll l,r,mini1=2018,mini2; cin>>l>>r;
    for(ll i=l; i<r; i++){
        for(ll j=i+1; j<=r; j++){
            mini2=(i*j)%mod;
            mini1= min(mini1,mini2);
            if(mini1==0) break;
        }
        if(mini1==0) break;
    }
    cout<<mini1<<endl;
}
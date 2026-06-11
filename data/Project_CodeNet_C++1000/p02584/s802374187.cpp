#include<iostream>
#include<math.h>
#include<bits/stdc++.h>
#include<queue>
#include<cstdio>
#define rep(i,n) for (int i=0;i<(n);++i)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    ll x,k,d;
    cin>>x>>k>>d;
    x = abs(x);
    ll ans;
    if(x/d >=k){
        ans = x-d*k;
    }else{
        ll e = x/d;
        k -= e;
        x -= e*d;
        if(k%2==1) x = abs(x-d);
        ans = x;
    }
    cout<<ans<<endl;
    return 0;
}
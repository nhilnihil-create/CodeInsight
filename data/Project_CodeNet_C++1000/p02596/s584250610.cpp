// #include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    ll k; cin >> k;
    ll x = 7;
    ll ans = 0;
    rep2(i,1001001){
        if(x%k==0) {
            ans = i;
            break;
        } else x = (10*x+7) % k;
    }
    if(!ans) cout << -1 << endl;
    else cout << ans << endl;
}

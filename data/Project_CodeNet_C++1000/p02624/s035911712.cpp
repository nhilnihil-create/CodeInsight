#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

ll sum(ll x){
    return x*(x+1)/2;
}

int main(){
    ll n; cin >> n;
    ll ans = 0;
    rep2(i,n+1){
        ans += i*sum(n/i);
    }
    cout << ans << endl;
}
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

ll dst(ll a, ll b, ll x, ll y){
    ll ans = abs(a-b);
    ans = min(ans,abs(a-x)+abs(b-y)+1);
    ans = min(ans,abs(a-y)+abs(b-x)+1);
    return ans;
}

int main(){
    ll n,x,y; cin >> n >> x >> y;
    vector<ll> ans(n+1,0);
    rep2(i,n){
        for(ll j=i+1; j<=n; j++){
            ans[dst(i,j,x,y)]++;
        }
    }
    rep2(i,n){
        cout << ans[i] << endl;
    }
}
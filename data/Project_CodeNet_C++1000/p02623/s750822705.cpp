#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cmath>

typedef long long ll;
using namespace std;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rep2(i,n) for(ll i=1;i<(n);i++)

ll gcd(ll a, ll b){
    if(a<b) swap(a,b);
    if(a%b == 0) return b;
    else return gcd(b,a%b);
}

int main(){
    ll n,m,k; cin >> n >> m >> k;
    vector<ll> a(n+1,0),b(m+1,0);
    rep2(i,n+1) {
        cin >> a[i];
        a[i]+=a[i-1];
    }
    rep2(i,m+1){
        cin >> b[i];
        b[i]+=b[i-1];
    }
    ll now = m;
    ll ans = 0;
    rep(i,n+1){
        bool flag = 1;
        while(flag && now > -1){
            if(a[i] + b[now] <= k){
                ans = max(ans,i+now);
                flag = 0;
            }
            while(a[i] + b[now] > k && flag){
                now--;
                if(now < 0) break;
            }
        }
    }
    cout << ans << endl;
}
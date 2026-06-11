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

int main(){
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    vector<bool> dob(n,1);
    rep(i,n-1){
        if(a[i] == a[i+1]){
            dob[i] = 0;
            dob[i+1]=0;
        }
    }
    ll amax = a[n-1]+1;
    vector<ll> dp(amax,0);
    rep(i,n){
        ll x = a[i];
        if(dp[x] == 0){
            for(int j = 1; j*x <= amax; j++){
                dp[j*x]++;
            }
        } else dp[x]++;
    }
    ll ans = 0;
    rep(i,n){
        if(dob[i] && dp[a[i]] == 1){
            ans++;
        }
    }
    // rep(i,n){
    //     cout << i << ": "<< a[i] << endl;
    // }
    // rep(i,amax){
    //     cout << i << ": " << dp[i] << endl;
    // }
    cout << ans << endl;
}
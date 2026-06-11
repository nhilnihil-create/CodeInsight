#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int mod = 1e9+7;
int main(){
    long n,k,ans=0;
    cin >> n >> k;
    long a[n];
    rep(i,n) cin >> a[i];
    long b[n],c[n];
    rep(i,n){
        long cnt=0,cnt1=0;
        rep(j,n){
            if(i<j&&a[i]>a[j]) cnt++;
            if(j<i&&a[i]>a[j]) cnt1++;
        }
        b[i] = cnt;
        c[i] = cnt1;
    }
    long d,e;
    if(k%2){
        d = k*((k+1)/2)%mod;
        e = k*((k-1)/2)%mod;
    }
    else{
        d= (k/2)*(k+1)%mod;
        e = (k/2)*(k-1)%mod;
    }
    rep(i,n){
        ans += (d*b[i])%mod + (e*c[i]) %mod;
        ans %= mod;
    }
    cout << ans << endl;
}
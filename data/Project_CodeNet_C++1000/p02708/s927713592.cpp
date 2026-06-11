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
ll mod = 1000000007;
int main(){
    ll n,k; cin >> n >> k;
    ll ans = 0;
    for(ll x=k;x<=n+1;x++){
        ans += (x*(n-x+1)+1)%mod;
        ans %= mod;
    }
    cout << ans << endl;
}
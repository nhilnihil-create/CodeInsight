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
    for(ll i=0;i<n;i++) cin >> a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    ll ans = a[0];
    ll cnt = 1;
    ll i = 1;
    while(true){
        if(cnt<n-2){
            ans += 2 * a[i];
            cnt += 2;
            i++;
        } else if(cnt == n-2) {
            ans += a[i];
            break;
        } else break;
    }
    cout << ans << endl;
}
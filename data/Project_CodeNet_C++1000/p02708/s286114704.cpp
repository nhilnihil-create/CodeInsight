#include<bits/stdc++.h>
#define ll long long
#define P pair<ll, ll>
using namespace std;

ll mod = 1e9 + 7;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;

    for(ll i=k;i<=n+1;i++){
        ans += i*(n-i+1) + 1;
        ans %= mod;
    }

    cout << ans << endl;
}
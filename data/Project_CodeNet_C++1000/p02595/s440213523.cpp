#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define fi first
#define se second
#define endl '\n'

int main(){

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, d; cin >>n >>d;

    ll ans = 0;
    for(int i = 0; i<n; i++){
        ll x, y; cin >>x >>y;
        if(d*d >= (x*x + y*y)) ans++;
    }

    cout <<ans <<endl;

    return 0;
}

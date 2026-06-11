#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

ll GCD(ll a, ll b){
    ll s = a, t = b;
    while(s%t != 0){
        ll u = s%t;
        s=t; t=u;
    }
    return t;
}

int main(){
    ll n, m; cin >> n >> m;
    ll gcd = 1;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    rep(i,n){
        gcd = gcd / GCD(gcd,a[i]) * a[i];
        if(gcd/2 > m){ cout << 0 << endl; return 0; }
    }
    ll ans = m/gcd;
    if(m - ans*gcd >= gcd/2) ans++;
    bool check = true;
    rep(i,n) if((gcd/a[i])%2 == 0) check = false;
    cout << (check ? ans : 0) << endl;
}
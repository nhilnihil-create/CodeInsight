#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

void solve(ll n, ll x, ll m, vector<ll> &d){
    int k = d.size();
    vector<ll> md(k, 0);
    ll ans = n - 1;
    for(int i=0; i<k; i++){
        md[i] = d[i]%m;
    }

    ll X = x;
    for(int i=0; i<k; i++){
        ll cnt;
        if(i + 1 <= n-1){
            cnt = (n-i-2)/k + 1;
        }else{
            cnt = 0;
        }
        if(md[i] == 0){
            ans -= cnt;
        }else{
            X += cnt*md[i];
        }
    }
    cout << ans - (X/m - x/m) << endl;
}

int main(){
    int k, q;  cin >> k >> q;
    vector<ll> d(k);
    for(int i=0; i<k; i++)
        cin >> d[i];
    
    while(q--){
        ll n, x, m;
        cin >> n >> x >> m;
        solve(n, x, m, d);
    }
}

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) ans += (i * (i + 1) / 2);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        ll mn = u, mx = n - v + 1;
        ans -= mn * mx;
    }
    cout << ans << '\n';


    return 0;
}




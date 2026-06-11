#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n, m; cin >> n >> m;
    vector<ll> a(n); ll res = 0;
    for(int i=0; i<n; ++i){cin >> a[i]; res += a[i];}
    if(n-res>=0){cout << n - res << endl;}
    else{cout << -1 << endl;}
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    ll ans  = -15*1e8;
    cin >> n;
    vector<int>b(n, 0);
    rep(i, n - 1){
        int a;
        cin >> a;
        b[a - 1] ++;
    }
    rep(i, n) cout << b[i] << endl;
    
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using ll = long long;

const int MOD = 1e9+7;

int main() {
    FASTIO
    
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll x = a*c, y = a*d, z = b*c, w = b*d;
    cout << max(x,max(y,max(z,w))) << "\n";
    
    return 0;
}
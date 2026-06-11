#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;

ll a[N];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++) cin >> a[i];
    x *= 2;
    ll lcm = a[0];
    for(int i = 1; i < n; i++){
        lcm = lcm / __gcd(lcm, a[i]) * a[i];
        if(lcm > x) return cout << 0, 0;
    }
    if(lcm > x) return cout << 0, 0;
    for(int i = 0; i < n; i++){
        if((lcm / a[i]) % 2 == 0) return cout << 0, 0;
    }
    cout << x / lcm - x / (2 * lcm);

    return 0;
}

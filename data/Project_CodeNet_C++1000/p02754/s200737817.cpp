#include <bits/stdc++.h>
using namespace std;

#define ll long long 

int main() {
    ios::sync_with_stdio(0); 

    ll n, a, b;
    cin >> n >> a >> b;

    if (a >= n) cout << n << endl;
    else {
        if (a + b >= n) {
            cout << a << endl;
        }
        else {
            ll ans = 0;
            ans += ( n / (a + b) ) * a;
            ans += min(n % (a + b), a);
            cout << ans << endl;
        }
    }





    return 0; 
}


#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
typedef long long ll;
typedef long double ld;


long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    ll X, Y;
    cin >> X >> Y;


    ll n = (2 * Y - X) / 3;
    ll m = (X - (2 * Y - X) / 3) / 2;

    if(n < 0 || m < 0 || (X + Y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    for(int i = n + m; i > m; i--){
        ans = (ans * i) % 1000000007;
        ans = ans * modinv(n + m + 1 - i, 1000000007) % 1000000007;
    }
    ans = ans % 1000000007;
    cout << ans << endl;

}
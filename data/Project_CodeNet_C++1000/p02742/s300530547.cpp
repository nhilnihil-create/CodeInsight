#include <bits/stdc++.h>
using namespace std;

#define INF 1e9
#define LLINF 1e18
#define pi 3.14159265358979323
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

int gcd(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return(gcd(b, a % b));
    }
}


int main() {
    ll h, w;
    ll ans = 0;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (h % 2 == 0) {
        ans = h / 2 * w;
    }
    else {
        ans = (h - 1) / 2 * w;
        ans += w / 2;
        if (w % 2 == 1) {
            ans++;
        }
    }
    cout << ans << endl;
}
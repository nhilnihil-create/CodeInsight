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
    int l, r, d;
    int ans = 0;
    cin >> l >> r >> d;
    rep(i, 200) {
        if (i * d >= l && i * d <= r) {
            ans++;
        }
    }
    cout << ans << endl;
}
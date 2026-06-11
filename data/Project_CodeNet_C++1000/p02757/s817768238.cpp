#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mods[100005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    string x;
    cin >> n >> p >> x;
    ll ans = 0;
    if (p == 2 || p == 5) {
        ll add = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((x[i] - '0') % p == 0) add++;
            ans += add;
        }
    }
    else {
        ll curr = 0, pow = 1;
        for (int i = n - 1; i >= 0; i--) {
            curr += (pow * (x[i] - '0')) % p;
            curr %= p;
            pow *= 10;
            pow %= p;
            ans += curr == 0;
            ans += mods[curr];
            mods[curr]++;
        }
    }
    cout << ans;
    return 0;
}

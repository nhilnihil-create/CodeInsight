#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define all(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
const int mod = 1e9+7;

int main() {
    ll n;
    cin >> n;
    if (n % 2 == 1) {
        cout << 0 << endl;
        return 0;
    }
    n /= 2;
    ll cnt = 0;
    ll r = 5;
    while (r <= n) {
        cnt += n / r;
        r *= 5;
    }
    cout << cnt << endl;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
int mod;
const int A = 1e5 + 2;

int add(int x, int y) {
    return ((x + y) % mod + mod) % mod;
}
int mul(int x, int y) {
    return (1LL * x * y) % mod;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n >> mod;
    int a[n];
    for (int i = 0; i < n; i++) {
        char x;
        cin >> x;
        a[i] = x - '0';
    }
    ll ans = 0;
    if (mod == 2 || mod == 5) {
        int acc = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] % mod == 0)
                acc++;
            ans += acc;
        }
        cout << ans;
        return 0;
    }
    int suf = 0, x = 1, acc[10001] = {};
    acc[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        suf = add(suf, mul(a[i], x));
        x = mul(x, 10);
        ans += acc[suf]++;
    }
    cout << ans;
    return 0;
}
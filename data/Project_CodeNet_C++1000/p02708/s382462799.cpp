#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int A = 2e5 + 5;
const int mod = 1e9 + 7;
int add(int x, int y) {
    return ((x + y) % mod + mod) % mod;
}
int mul(int x, int y) {
    return (1LL * x * y) % mod;
}
int fp (int x, int y) {
    if (!y) return 1;
    int acc = fp(x, y / 2);
    acc = mul(acc, acc);
    if (y & 1) acc = mul(acc, x);
    return acc;
}
int fact[A], inv[A];
void pre() {
    fact[0] = inv[0] = 1;
    for (int i = 1; i < A; i++) {
        fact[i] = mul(fact[i - 1], i);
        inv[i] = fp(fact[i] , mod - 2);
    }
}
int ncr(int n, int r) {
    return mul(fact[n], mul(inv[n - r], inv[r]));
}
int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    n++, pre();
    int ans = 0;
    for (int i = k; i <= n; i++) {
//        int l = i * (i - 1) / 2, r = n * (n - 1) / 2 - (n - i) * (n - i - 1) / 2;
        int l = ncr(i, 2) , r = add(ncr(n, 2), -ncr(n - i, 2));
        ans = add(ans, add(add(r, -l), 1));
//        cout << l << ' ' << r << '\n';
    }
    cout << ans;
    return 0;
}
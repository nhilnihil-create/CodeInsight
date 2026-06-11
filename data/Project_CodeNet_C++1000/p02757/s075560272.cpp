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
int fp(int x, int y) {
	if (!y) return 1;
	ll acc = fp(x, y / 2);
	acc = mul(acc, acc);
	if (y & 1) acc = mul(acc, x);
	return acc;
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
    int suf[n + 1], acc[10001] = {};
    suf[n] = 0, acc[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = add(suf[i + 1], mul(a[i], fp(10, n - i - 1)));
        ans += acc[suf[i]]++;
    }
    cout << ans;
    return 0;
}

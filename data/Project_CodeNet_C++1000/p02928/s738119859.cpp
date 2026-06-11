#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1000000007;

int main() {
    int n;
    ll k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) ans++;
        }
    }
    ans = ans * k % mod;

    int smaller[n];
    for (int i = 0; i < n; i++) {
        smaller[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i] > a[j]) smaller[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        int add = (ll) smaller[i] * ((k - 1) * k / 2 % mod) % mod;
        ans = (ans + add) % mod;
    }

    cout << ans << endl;
    return 0;
}
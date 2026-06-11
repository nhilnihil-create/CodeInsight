#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define pb push_back
#define all(x) x.begin(), x.end()
#define pi pair<int, int>
#define l first
#define r second
#define int long long

using namespace std;

const int maxn = 1e6 + 1;

int a[maxn], x[maxn];
int fc[maxn];
bool ec[maxn];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        fc[i] = fc[i - 1];
        for (int x = i; x % 2 == 0; x /= 2)
            ++fc[i];
    }
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        a[i] = c - '1';
    }
    bool ho = 0;
    for (int i = 0; i < n; i++)
        ho |= (a[i] == 1);
    for (int i = 0; i < n; i++)
        ec[i] = (fc[n - 1] - fc[i] - fc[n - i - 1] > 0);
    if (!ho) {
        int ans = 0;
        for (int i = 0; i < n; i++)
            if (!ec[i]) ans ^= a[i];
        cout << ans;
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (!ec[i]) ans ^= (a[i] % 2);
    cout << ans;
    return 0;
}

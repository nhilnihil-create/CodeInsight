#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

constexpr long long mod = 1000000007;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long n, k;
    cin >> n >> k;

    vll a(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        a[i + 1] = a[i] + i;
    }

    ll cnt = 0;
    for (int i = k; i <= n + 1; i++) {
        cnt += a[n + 1] - a[n + 1 - i ] - a[i] + 1;

        cnt %= mod;
    }

    cout << cnt << endl;
}
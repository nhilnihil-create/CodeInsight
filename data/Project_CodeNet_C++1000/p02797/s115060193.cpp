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

    ll n, k, s;
    cin >> n >> k >> s;

    vll a(n);

    if (s == 1000000000) {
        for (int i = 0; i < k; i++){
            a[i] = s;
        }
        for (int i = k; i < n; i++){
            a[i] = s - 1;
        }
    } else {
        for (int i = 0; i < k; i++) {
            a[i] = s;
        }
        for (int i = k; i < n; i++) {
            a[i] = s + 1;
        }
    }

    rep(i, n) cout << a[i] << " ";
    cout << endl;
}
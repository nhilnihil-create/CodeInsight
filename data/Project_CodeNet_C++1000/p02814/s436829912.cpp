#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int count_divive2(int x) {
    int ans = 0;
    while (x % 2 == 0) {
        ans++;
        x /= 2;
    }

    return ans;
}

void solve() {
    ll N, M;
    cin >> N >> M;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int cntpow2 = count_divive2(a[0]);
    for (int i = 0; i < N; i++) {
        if (cntpow2 != count_divive2(a[i])) {
            cout << 0 << endl;
            return;
        }
    }

    ll T = a[0] / 2;
    for (int i = 0; i < N; i++) {
        T = lcm(T, a[i] / 2);
    }

    // cout << M << endl;
    // cout << T << endl;
    cout << M / T / 2 + (M / T % 2) << endl;

}

int main() {
    solve();
    return 0;
}

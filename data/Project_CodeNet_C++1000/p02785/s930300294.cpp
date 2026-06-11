#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<ll> H(N);
    rep(i, N) { cin >> H[i]; }

    sort(all(H), greater<int>());
    ll ans = 0;
    rep(i, N) {
        if (i < K)
            continue;
        else {
            ans += H[i];
        }
    }

    cout << ans << endl;
}
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define ll long long
#define ld long double
#define INF 1000000000000000000
typedef pair<ll, ll> pll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<ll> A(N + 1), sum(N + 1);
    rep(i, N + 1) {
        cin >> A[i];
        sum[i] = A[i];
    }

    for (int i = N; i > 0; i--) {
        sum[i - 1] += sum[i];
    }

    ll ans = 0, node = 1;
    rep(i, N) {
        ans += node;
        if (node - A[i] <= 0) {
            cout << -1 << endl;
            return 0;
        }
        if ((node - A[i]) * 2 <= sum[i + 1]) {
            node = (node - A[i]) * 2;
        } else {
            node = sum[i + 1];
        }
    }
    if (node != A.back()){
        cout << -1 << endl;
        return 0;
    }

    ans += node;

    cout << ans << endl;
    return 0;
}
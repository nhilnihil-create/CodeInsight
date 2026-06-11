#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll N;
vector<ll> A;
int main() {
    cin >> N;
    A.resize(N);
    rep(i, N) cin >> A[i];

    vector<ll> sum(N + 1);

    rep(i, N) {
        sum[i + 1] = sum[i] + A[i]; 
        // cout << sum[i] << " " << A[i];
        // cout << endl;
    }

    ll total = 0;
    rep(i, N) {
        total += A[i];
    }
    // cout << total << endl;
    ll ans = INF;
    for (int i = 1; i <= N; i++) {
        // cout << sum[i] << endl;
        ll left = sum[i];
        ll right = total - left; 
        ll tmp = left -right;
        // cout << left << " " << right << endl;
        if (tmp < 0) tmp = -tmp;
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}
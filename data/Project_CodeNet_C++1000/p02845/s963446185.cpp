#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,n) for(int i=(a); i<(n); i++)
#define all(v) v.begin(), v.end()
#define fi first
#define se second
using namespace std;
using ll = long long;
using P = pair<int ,int>;
const int INF = 1e9;
const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n, 0);
    ll ans = 1ll;
    rep(i, n) {
        int x; cin >> x;
        if (x==0) ans *= ll(3ll-a[0]);
        else ans *= ll(a[x-1]-a[x]);
        ans %= MOD;
        a[x]++;
    }

    cout << ans << endl;
}
#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;
#define fr first
#define sc second
#define pii pair<int, int>
#define all(v) v.begin(), v.end()

using namespace std;

const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    ll ans = 0;
    vector<vector<int> > g(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<ll> comp(n + 1, 0);
    vector<bool> marked(n + 1, false);
    ll sum = 0;

    for (int i = 1; i <= n; i++) {
        ll val = 1;
        for (int ot : g[i])
            if (marked[ot]) val--;
        comp[i] = val;
        sum += (n + 1 - i) * val;
        marked[i] = true;
    }

    ans = sum;

    for (int i = 1; i < n; i++) {
        //eliminate i
        sum -= (n + 1 - i) * comp[i];
        for (int ot : g[i]) {
            if (ot > i) {
                comp[ot]++;
                sum += (n + 1 - ot);
            }
        }
        ans += sum;
    }

    cout << ans;

    return 0;
}

#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int p[5010];
ll c[5010], ans = -1e18;

int main() {
    ios_base::sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=0;i<n;i++) {
        cin >> p[i];
        p[i]--;
    }
    for (int i=0;i<n;i++) cin >> c[i];

    for (int i=0;i<n;i++) {
        int q = i;
        ll now = 0, mx = -1e18;
        vector<ll> t;
        do {
            q = p[q];
            now += c[q];
            t.pb(now);
        } while (q!=i);
        ll mxv = max(0LL, t.back());
        for (int j=0;j<t.size();j++) {
            if (j+1>k) break;
            ans = max(ans, mxv*((k-j-1)/(int)t.size())+t[j]);
        }
    }

    cout << ans << endl;
}

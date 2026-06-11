#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 1e9 + 7;

signed main() {
    int n, x, l;
    cin>>n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin>>x>>l;
        v.push_back(make_pair(x + l, x - l));
    }
    sort(v.begin(), v.end());
    int ans = 0, now = -INF;
    for (auto p: v) {
        if (now <= p.second) {
            ans++;
            now = p.first;
        }
    }
    cout<<ans<<endl;
}

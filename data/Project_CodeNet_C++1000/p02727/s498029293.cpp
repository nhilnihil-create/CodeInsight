#include <bits/stdc++.h>
using namespace std;
#define INCANT cin.tie(0), cout.tie(0), ios::sync_with_stdio(0), cout << fixed << setprecision(20);
#define int long long
const int INF = 1e18, MOD = 1e9 + 7;
int x, y, a, b, c, n;

signed main() {
    cin>>x>>y>>a>>b>>c;
    vector<pair<int, int>> v;
    for (int i = 0; i < a; i++) {
        cin>>n;
        v.push_back(make_pair(n, 1));
    }
    for (int i = 0; i < b; i++) {
        cin>>n;
        v.push_back(make_pair(n, 2));
    }
    for (int i = 0; i < c; i++) {
        cin>>n;
        v.push_back(make_pair(n, 0));
    }
    sort(v.rbegin(), v.rend());
    int cnt = 0;
    int ans = 0;
    for (auto p: v) {
        if (p.second == 0) cnt++, ans += p.first;
        if (p.second == 1 && x) x--, ans += p.first;
        if (p.second == 2 && y) y--, ans += p.first;
        if (x + y - cnt == 0) break;
        
    }
    cout<<ans<<endl;
}
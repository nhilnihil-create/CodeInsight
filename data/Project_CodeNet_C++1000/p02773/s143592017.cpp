#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int MAXN = 1e5 + 10;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    map<string, int> ma;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ma[s]++;
        mx = max(mx, ma[s]);
    }
    for (auto &c : ma) {
        if (c.se == mx) cout << c.fi << "\n";
    }
    return 0;
}

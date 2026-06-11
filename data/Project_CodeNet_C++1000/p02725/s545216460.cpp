#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const int mod = 1e9 + 7;
const int MAXN = 5e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int mx = 0;
    int k, n;
    cin >> k >> n;
    vector<int> a(n);
    for (auto &c : a) cin >> c;
    for (int i = 0; i < n - 1; i++) mx = max(mx, a[i + 1] - a[i]);
    mx = max(mx, a[0] + k - a[n - 1]);
    cout << k - mx;
    return 0;
}

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
    int n;
    cin >> n;
    vector<int> ans(n);
    int x, y;
    cin >> x >> y;
    x--; y--;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            ans[min(j - i, abs(i - x) + 1 + abs(j - y))]++;
            //cout << i + 1 << " " << j + 1 << " " << min(j - i, abs(i - x) + 1 + abs(j - y)) << endl;
        }
    }
    for (int i = 1; i < n; i++) cout << ans[i] << "\n";
    return 0;
}

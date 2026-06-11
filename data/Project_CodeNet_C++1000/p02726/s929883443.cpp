#include <bits/stdc++.h>
#define repl(i, l, r) for (int i = l; i < r; ++i)
#define rep(i, n) repl(i, 0, n)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using G = vector<vector<int>>;
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    --x;
    --y;
    vector<int> ans(n);
    rep(l, n-1) {
        for(int r = l + 1; r < n; ++r) {
            int c = abs(x-l);
            int d = abs(y-r);
            int e = min(r-l, c+d+1);
            ++ans[e];
        }
    }
    repl(i, 1, n) {
        cout << ans[i] << endl;
    }
    return 0;
}

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
const int MOD = 1000000007;
const int INF = 1001001001;
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, -1, 0, 1};

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int l = 0;
    int r = 1e9;
    while(r - l > 1) {
        int x = (l + r) / 2;
        auto f = [&](int x) {
            ll now = 0;
            rep(i, n) {
                now += (a[i] - 1) / x;
            }
            return now <= k;
        };
        if(f(x)) r = x; else l = x;
    }
    cout << r << endl;
    return 0;
}

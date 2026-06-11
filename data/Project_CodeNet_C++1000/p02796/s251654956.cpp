#include <bits/stdc++.h>
#define repl(i, l, r) for (ll i = l; i < r; ++i)
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
    int n;
    cin >> n;
    vector<P> v(n);
    rep(i, n) {
        int x, l;
        cin >> x >> l;
        v[i].first = x + l;
        v[i].second = x - l;
    }
    sort(all(v));
    int ans = n;
    int r = v[0].first;
    repl(i, 1, n) {
        if(r > v[i].second) {
            --ans;
        }
        else r = v[i].first;
    }
    cout << ans << endl;
    return 0;
}

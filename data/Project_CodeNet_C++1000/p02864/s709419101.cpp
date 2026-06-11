//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define db long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()

void dout() { cerr << '\n'; }

template <typename Head, typename... Tail>
void dout(Head H, Tail... T) {
    cerr << " " << H;
    dout(T...);
}

#ifdef LOCAL
    #define dbg(...) cerr << #__VA_ARGS__, dout(__VA_ARGS__)
#else
    #define dbg(...) ;
#endif

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair <int, int> pii;

const int N = 305;
const ll inf = 1e18;
int n, k, h[N], m;
ll dp[N][N][N], p[N][N][N], s[N][N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
    #endif

    cin >> n >> k;
    vector <int> vec;
    vec.pb(0);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        vec.pb(h[i]);
    }
    sort(all(vec));
    vec.erase(unique(all(vec)), vec.end());
    m = vec.size();
    memset(& dp, 0x3f, sizeof(dp));
    memset(& p, 0x3f, sizeof(p));
    memset(& s, 0x3f, sizeof(s));
    dp[0][0][1] = 0;
    for (int i = 1; i <= m; i++) {
        p[0][0][i] = 0;
    }
    s[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int l = 1; l <= m; l++) {
                int cost = (vec[l - 1] != h[i]);
                if (cost <= j) {
                    dp[i][j][l] = vec[l - 1] + p[i - 1][j - cost][l - 1];
                    dp[i][j][l] = min(dp[i][j][l], s[i - 1][j - cost][l]);
                }
                p[i][j][l] = min(p[i][j][l - 1], dp[i][j][l] - vec[l - 1]);
            }
            for (int l = m; l >= 1; l--) {
                s[i][j][l] = min(s[i][j][l + 1], dp[i][j][l]);
            }
        }
    }
    ll res = inf;
    for (int i = 0; i <= k; i++) {
        for (int j = 1; j <= m; j++) {
            res = min(res, dp[n][i][j]);
        }
    }
    cout << res;
}

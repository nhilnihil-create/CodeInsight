#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long
#define all(_v) _v.begin(), _v.end()
#define pii pair <int, int>
#define pll pair <ll, ll>
#define pvllvll pair <vector <ll>, vector <ll> >
#define ld long double
#define veci vector <int>
#define vecll vector <ll>


const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
const double PI = 3.1415926535897932384626433832795;
const double eps = 1e-9;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;

const int MAXN = 3e5 + 10;
int cnt1[MAXN], cnt2[MAXN];
void solve() {
    int h, w, n;
    cin >> h >> w >> n;
    set <pii> a;
    for(int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        cnt1[x]++;
        cnt2[y]++;
        a.insert(mp(x, y));
    }
    int mx = *max_element(cnt1 + 1, cnt1 + h + 1);
    int mx2 = *max_element(cnt2 + 1, cnt2 + w + 1);
    veci x, y;
    for(int i = 1; i <= h; ++i) if(cnt1[i] == mx) x.pb(i);
    for(int i = 1; i <= w; ++i) if(cnt2[i] == mx2) y.pb(i);
    int ans = 0;
    for(auto v : x)
        for(auto u : y) {
            int ch = a.count(mp(v, u));
            ans = max(ans, cnt1[v] + cnt2[u] - ch);
            if(!ch) break;
        }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    ///cin >> T;
    while(T--) solve(), cout << '\n';
    return 0;
}

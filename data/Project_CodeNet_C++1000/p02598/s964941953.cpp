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

int n, k;
ll a[(int)2e5+10];
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    ll l = 1, r = 1e9, res = -1;
    while(l <= r) {
        ll mid = l + r >> 1;
        ll ans = 0;
        for(int i = 1; i <= n; ++i) ans += (a[i] + mid - 1) / mid;
        if(ans - n <= k) res = mid, r = mid - 1;
        else l = mid + 1;
    }
    cout << res;
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

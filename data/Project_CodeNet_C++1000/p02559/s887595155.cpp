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

ll fw[(int)5e5+10];
int n, q;

void upd(int p, ll val) {
    for(;p <= n; p += (p & -p)) fw[p] += val;
}

ll sum(int r) {
    ll res = 0;
    for(; r > 0; r -= (r & -r)) res += fw[r];
    return res;
}
void solve() {
    cin >> n >> q;
    for(int i = 1; i <= n; ++i) {
        ll x;
        cin >> x;
        upd(i, x);
    }
    while(q--) {
        int t, p, x;
        cin >> t >> p >> x;
        if(!t) upd(p + 1, x);
        else cout << sum(x) - sum(p) << '\n';
    }
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
